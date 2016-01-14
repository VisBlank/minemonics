//# corresponding headers
#include <controller/viewcontroller/ViewController.hpp>

//# forward declarations
//# system headers
#include <stddef.h>
#include <iterator>

//## controller headers
//## model headers
//## view headers
#include <CEGUI/FontManager.h>
#include <CEGUI/GUIContext.h>
#include <CEGUI/Logger.h>
#include <CEGUI/MouseCursor.h>
#include <CEGUI/NamedXMLResourceManager.h>
#include <CEGUI/SchemeManager.h>
#include <CEGUI/Singleton.h>
#include <CEGUI/Size.h>
#include <CEGUI/String.h>
#include <CEGUI/System.h>
#include <CEGUI/Vector.h>
#include <CEGUI/Window.h>
#include <CEGUI/WindowManager.h>
#include <OgreRenderWindow.h>
#include <Renderer.h>

//# custom headers
//## base headers
#include <SimulationManager.hpp>

//## configuration headers
#include <configuration/CEGUIConfiguration.hpp>
#include <configuration/GUIConfiguration.hpp>

//## controller headers
//## model headers
//## view headers
#include <view/visualization/CEGUI/configpanels/EditPlanetPanel.hpp>
#include <view/visualization/CEGUI/configpanels/EditPopulationPanel.hpp>
#include <view/visualization/CEGUI/configpanels/LoadPlanetPanel.hpp>
#include <view/visualization/CEGUI/configpanels/LoadPopulationPanel.hpp>
#include <view/visualization/CEGUI/configpanels/NewPlanetPanel.hpp>
#include <view/visualization/CEGUI/configpanels/NewPopulationPanel.hpp>
#include <view/visualization/CEGUI/infopanels/DetailsPanel.hpp>
#include <view/visualization/CEGUI/infopanels/FPSPanel.hpp>
#include <view/visualization/CEGUI/MenuBar.hpp>

//## utils headers

BoostLogger ViewController::mBoostLogger; /*<! initialize the boost logger*/
ViewController::_Init ViewController::_initializer;
ViewController::ViewController() :
	mRenderer(NULL), mLayout(NULL), mSystem(NULL), mDragContainer(NULL), mEvaluationInView(
	NULL), mShowShadows(false), mMenuBar(NULL), mFpsPanel(
	NULL), mDetailsPanel(NULL), mNewPlanetWindow(NULL), mNewPopulationWindow(
	NULL), mEditPlanetWindow(), mEditPopulationWindow(NULL), mLoadPlanetWindow(
	NULL), mLoadPopulationWindow(NULL),mChaosControllerPanel(NULL),mJointDynamicsPanel(NULL) {
}

ViewController::~ViewController() {
	mLayout = NULL;

	mSystem = NULL;

	mEvaluationInView = NULL;

	mPlanetsInView.clear();

	mRenderer = NULL;

	delete mDragContainer;
	mDragContainer = NULL;

	delete mMenuBar;
	mMenuBar = NULL;

//	delete mFpsPanel;
//	mFpsPanel = NULL;

//	delete mDetailsPanel;
//	mDetailsPanel = NULL;

	delete mNewPlanetWindow;
	mNewPlanetWindow = NULL;

	delete mNewPopulationWindow;
	mNewPopulationWindow = NULL;

	delete mEditPlanetWindow;
	mEditPlanetWindow = NULL;

	delete mEditPopulationWindow;
	mEditPopulationWindow = NULL;

	delete mLoadPlanetWindow;
	mLoadPlanetWindow = NULL;

	delete mLoadPopulationWindow;
	mLoadPopulationWindow = NULL;
}

void ViewController::initialize(Ogre::RenderTarget* const renderTarget) {

	mCameraHandler.initialize();

	// CEGUI
	// with a scene manager and window, we can create a the GUI renderer
	// new way to instantiate a CEGUIOgreRenderer (Ogre 1.9)
	mRenderer = &CEGUI::OgreRenderer::bootstrapSystem(*renderTarget);

	// This pointer is valid only locally
	mSystem = &CEGUI::System::getSingleton();

	// tell us a lot about what is going on (see CEGUI.log in the working directory)
	CEGUI::Logger::getSingleton().setLoggingLevel(CEGUI::Warnings);

	// use this CEGUI scheme definition (see CEGUI docs for more)
	CEGUI::SchemeManager::getSingleton().createFromFile(
		CEGUIConfiguration::CEGUI_SCHEME + ".scheme", (CEGUI::utf8*) "GUI");

	// hide the CEGUI mouse cursor (defined in the look-n-feel)
	mSystem->getDefaultGUIContext().getMouseCursor().setDefaultImage(NULL);

	// use this font for text in the UI
	CEGUI::FontManager::getSingleton().createFromFile("Tahoma-8.font",
		(CEGUI::utf8*) "GUI");
	mSystem->getDefaultGUIContext().setDefaultFont("Tahoma-8");

	// load a layout from the XML layout file (you'll find this in resources/gui.zip), and
	// put it in the GUI resource group
	mLayout = CEGUI::WindowManager::getSingleton().createWindow(
		(CEGUI::utf8*) "DefaultWindow", (CEGUI::utf8*) "Sheet");

	// add menu
	mMenuBar = new MenuBar();
	mLayout->addChild(mMenuBar->getWindow());

	// store window width and height
	int windowWidth =
		(int) SimulationManager::getSingleton()->getWindow()->getWidth();
	int windowHeight =
		(int) SimulationManager::getSingleton()->getWindow()->getHeight();

	// add fps panel
	mFpsPanel = new FPSPanel(CEGUIConfiguration::INFOPANEL_BORDER,
		(int) windowHeight * 4.0f / 5.0f);
	mMovablePanels.push_back(mFpsPanel);

	// add details panel
	mDetailsPanel = new DetailsPanel(
		(int) windowWidth - 200 - 3 * CEGUIConfiguration::INFOPANEL_BORDER,
		(int) windowHeight / 6.0f);
	mDetailsPanel->hide();
	mMovablePanels.push_back(mDetailsPanel);

	// initialize windows
	//# new planet window
	mNewPlanetWindow = new NewPlanetPanel(windowWidth / 3.0f,
		windowHeight / 6.0f, GUIConfiguration::newPlanetName);
	mNewPlanetWindow->hide();
	mMovablePanels.push_back(mNewPlanetWindow);

	mNewPopulationWindow = new NewPopulationPanel(windowWidth / 3.0f,
		windowHeight / 4.0f, GUIConfiguration::newPopulationName);
	mNewPopulationWindow->hide();
	mMovablePanels.push_back(mNewPopulationWindow);

	mEditPlanetWindow = new EditPlanetPanel(windowWidth / 3.0f,
		windowHeight / 4.0f, GUIConfiguration::editPlanetName);
	mEditPlanetWindow->hide();
	mMovablePanels.push_back(mEditPlanetWindow);

	mEditPopulationWindow = new EditPopulationPanel(windowWidth / 3.0f,
		windowHeight / 4.0f, GUIConfiguration::editPopulationName);
	mEditPopulationWindow->hide();
	mMovablePanels.push_back(mEditPopulationWindow);

	mLoadPlanetWindow = new LoadPlanetPanel(windowWidth / 3.0f,
		windowHeight / 4.0f, GUIConfiguration::loadPlanetName);
	mLoadPlanetWindow->hide();
	mMovablePanels.push_back(mLoadPlanetWindow);

	mLoadPopulationWindow = new LoadPopulationPanel(windowWidth / 3.0f,
		windowHeight / 4.0f, GUIConfiguration::loadPopulationName);
	mLoadPopulationWindow->hide();
	mMovablePanels.push_back(mLoadPopulationWindow);

	mChaosControllerPanel = new MathGLPanel("Chaos controller state",((float)windowWidth) / 1.37f, windowHeight / 100.0f, 500,
		500, SimulationManager::getSingleton()->getRoot(), 500, 500);
	mChaosControllerPanel->hide(); // hide the panel by default

	mMovablePanels.push_back(mChaosControllerPanel);

	mJointDynamicsPanel = new MathGLPanel("Joint dynamics",((float)windowWidth) / 1.37f, windowHeight / 2.0f, 500,
		500, SimulationManager::getSingleton()->getRoot(), 500, 500);
	mJointDynamicsPanel->setXLabel("x: joint x[-Pi;Pi]");
	mJointDynamicsPanel->setYLabel("y:joint dx[1/s]");
	mJointDynamicsPanel->setHorizontalRotation(0);
	mJointDynamicsPanel->setVerticalRotation(0);
	mJointDynamicsPanel->hide(); // hide the panel by default

	mMovablePanels.push_back(mJointDynamicsPanel);
//
//	mMovablePanels.push_back(
//		new ShowCasePanel(0, 30, "ShowcasePanel", 1800, 1000));

	// add all movable panels to the layout
	std::vector<MovablePanel*>::const_iterator it = mMovablePanels.begin();
	for (; it != mMovablePanels.end(); it++) {
		mLayout->addChild((*it)->getWindow());
	}

	// you need to tell CEGUI which layout to display. You can call this at any time to change the layout to
	// another loaded layout (i.e. moving from screen to screen or to load your HUD layout). Note that this takes
	// a CEGUI::Window instance -- you can use anything (any widget) that serves as a root window.
	mSystem->getDefaultGUIContext().setRootWindow(mLayout);

	// make an instance of our GUI sheet handler class
	mGUISheetHandler.initialize(mSystem, mLayout);

	mInfoOverlay.initialize(mCameraHandler.getCamera());

	// TODO: Add light to the camera like a head light of a miner #134.
//	Ogre::Light* light = simulationManager->getSceneManager()->createLight(
//			"headLight");
//	light->setType(Ogre::Light::LT_DIRECTIONAL);
//	light->setPosition(simulationManager->getCamera()->getPosition());
//	light->setDirection(simulationManager->getCamera()->getDirection());
//	light->setDiffuseColour(Ogre::ColourValue::White);
//	light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));
//	simulationManager->getCameraHandler().getCamNode()->attachObject(light);

}

void ViewController::update(const double timeSinceLastFrame) {

	mInfoOverlay.update(); /**!< update the information overlay */

	mCameraHandler.reposition(timeSinceLastFrame); /**!< reposition the camera */

}

void ViewController::notifyDisplaySizeChanged(const float width,
	const float height) {
	mSystem->notifyDisplaySizeChanged(CEGUI::Size<float>(width, height));
}

void ViewController::updateMousePosition(const float mousePositionX,
	const float mousePositionY) {
	CEGUI::Vector2f mousePos =
		mSystem->getDefaultGUIContext().getMouseCursor().getPosition();
	CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseMove(
		mousePositionX - mousePos.d_x, mousePositionY - mousePos.d_y);
}

void ViewController::addPlanetToView(Planet* const planet) {
	mPlanetsInView.push_back(planet);
}

void ViewController::removePlanetFromView(Planet* const planet) {
	for (std::vector<Planet*>::iterator pit = mPlanetsInView.begin();
		pit != mPlanetsInView.end(); pit++) {
		if ((*pit) == planet) {
			mPlanetsInView.erase(pit);
			break;
		}
	}
}
