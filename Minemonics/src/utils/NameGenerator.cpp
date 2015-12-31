//# corresponding header
#include <utils/NameGenerator.hpp>
#include <string>

//## controller headers
//## model headers
//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
//## model headers
//## view headers
//## utils headers

NameGenerator::NameGenerator() {
	initialize();

}

NameGenerator::~NameGenerator() {
}

void NameGenerator::initialize() {
	// the prefix and suffix lists are mainly extracted from:
	// http://www.realelvish.net/namelists.php
	// They might (what am I saying for sure) contain duplicates and that messes sightly
	// with the probability of one being chosen but it does not matter much. Enjoy!
	std::string namePrefix[] = {
			"", //who said we need to add a prefix?
			//dwarfish
			"B", "Gil", "Bal", "Gim", "Bel", "Kil", "Bof", "Mor", "Bol", "Nal",
			"D", "Nor", "Dal", "Ov", "Dor", "Th", "Dw", "Thor", "Far", "Thr",
			//elvish
			"Aer", "Af", "Ah", "Al", "Am", "Ama", "An", "Ang", "Ansr", "Ar",
			"Arì", "Arn", "Aza", "Bael", "Bes", "Cael", "Cal", "Cas", "Cla",
			"Cor", "Cy", "Dae", "Dho", "Dre", "Du", "Eil", "Eir", "El", "Er",
			"Ev", "Fera", "Fi", "Fir", "Fis", "Gael", "Gar", "Gil", "Ha", "Hu",
			"Ia", "Il", "Ja", "Jar", "Ka", "Kan", "Ker", "Keth", "Koeh", "Kor",
			"La", "Laf", "Lam", "Lue", "Ly", "Mai", "Mal", "Mara", "My", "Na",
			"Nai", "Nim", "Nu", "Ny", "Py", "Raer", "Re", "Ren", "Ru", "Rua",
			"Rum", "Rid", "Sae", "Seh", "Sel", "Sha", "She", "Si", "Sim", "Sol",
			"Sum", "Syl", "Ta", "Tahl", "Tha", "Tho", "Ther", "Thro", "Tia",
			"Tra", "Uth", "Ver", "Vil", "Von", "Ya", "Za", "Zy",
			//men
			"Adan", "Beo", "Grim", "Ceol", "Esc", "Theod", "Elf", "Esc",
			"Beord", "Cwen", "Leof", "Here", "Wulf", "Beleg", "Fela", "Gil",
			"Curu", "Ul", "Breg", "Hir", "Ir", "Rod", "Sael", "Bel", "Galadh",
			"Nim", "Tinu", "Edhel",
			//hobbits
			"Ever", "Ferd", "Isen", "Dino",
			//more elvish
			"Aman", "Boro", "Celeb", "Mor", "Hur", "Dun", "Galad", "Lego",
			"Fëan", "El", "Bere", "Isil", "Fin", "Mor", "Hal", "Eär", "Bele",
			"Ar", "Fara", "Nol", "Elen", "Vala", "Gil", "Lin", "Sir", "Tur",
			//quenya prefix
			"Alata", "Alta", "Alwa", "Anda", "Angol", "Antara", "Arca", "Autha",
			"Axëa", "Caila", "Caimassë", "Caimassëa", "Carnifinda",
			"Carningorto", "Céva", "Corima", "Corna", "Cú", "Cumna", "Cúna",
			"Eldasilquë", "Engwa", "Enwina", "Eteminya", "Fana", "Fanga",
			"Fangë", "Fanwa", "Fassë", "Fauca", "Fimbë", "Findelë", "Fínëa",
			"Halda", "Halla", "Halya-", "Hanaco", "Harna", "Harwë", "Haura",
			"Helda", "Hendumaica", "Hendunárë", "Hendunívë", "Holwë", "Holwëa",
			"Hurin", "Hwarin", "Ilfirin", "Inya", "Írima", "Laica", "Laiwa",
			"Landa", "Larca", "Lassecanta", "Lauca", "Laurëaloxë", "Lelya",
			"Lenca", "Lenwa", "Leptafinya", "Limbë", "Limpa", "Linda",
			"Lindalëa", "Lindóma", "Linquë", "Linta", "Linyenwa", "Lissë",
			"Lótëaloxë", "Loxa", "Lusta", "Maita", "Malwafinda", "Maxa",
			"Milya", "Minda", "Mintë", "Mitsa", "Mixa", "Morifindë",
			"Morivanya", "Morna", "Muilë", "Muina", "Mussë", "Náha", "Naica",
			"Naicë", "Naicelë", "Naicelëa", "Naira", "Narwa", "Narwanta",
			"Narwafinda", "Nauca", "Néna", "Nenda", "Nenya", "Nerca", "Netha",
			"Nethima", "Netya", "Níca", "Nimpa", "Nimpë", "Nincë", "Nindë",
			"Ninquë", "Nípa", "Nirwa", "Nirwastir", "Nirwë", "Nísima", "Nítë",
			"Nitya", "Nórima", "Norna", "Northa", "Numba", "Ñolda", "Ñollótë",
			"Ñolya", "Orna", "Ornalaurëa", "Orwa", "Palla", "Parca", "Parna",
			"Passa", "Pasta", "Pertunda", "Pia", "Picina", "Pincë",
			"Pirucendëa", "Pitya", "Poica", "Polda", "Púrëa", "Quanta", "Quel-",
			"Quilinqua", "Rácina", "Raina", "Rámavoitë", "Rembina", "Rempa",
			"Ría", "Ríë", "Rië", "Riel", "Riendë", "Rihta-", "Rimpa", "Rína",
			"Rinda", "Ringa", "Roina", "Ronda", "Ruina", "Runda", "Russa",
			"Russafinda", "Russaloxë", "Russë", "Russelda", "Sarda", "Sarna",
			"Soica", "Taina", "Tára", "Tarya", "Tauca", "Terellëo", "Teren",
			"Tereva", "Thaura", "Thenna", "Thinta", "Titta", "Tiuca", "Tiuya-",
			"Toa", "Torna", "Tornanga", "Tumna", "Tunda", "Tunga", "Tuo",
			"Tyelca", "Tyelpefinda", "Úfanwa", "Úfanwëa", "Unqua", "Úra", "Úrë",
			"Uruitë", "Úruva", "Úvanëa", "Úvanima", "Vanëa", "Vanessë", "Vanië",
			"Vanima", "Vanimelda", "Vanimórë", "Vanisaila", "Vanithaura",
			"Vanya", "Wahta-", "Waina", "Wára", "Wathar", "Wëa", "Wëassë",
			"Wén", "Wenya", "Winya", "Wirya", "Yalúmëa", "Yámë", "Yána",
			"Yanda", "Yanga-", "Yára", "Yárëa", "Yerna",
			//quenya personality
			"Aica", "Alasaila", "Alassë", "Alasselóra", "Alassindo", "Alima",
			"Alma", "Almarë", "Almárëa", "Alya", "Alya", "Apsen", "Aranya",
			"Arata", "Aravaldëa", "Arta", "Astar", "Athëa", "Athya", "Avanwa",
			"Awalda", "Cánë", "Canya", "Caurë", "Caurëa", "Costa", "Cotto",
			"Cotumo", "Cotya", "Curulambë", "Estel", "Faica", "Faila", "Fárëa",
			"Fëalassë", "Fëamára", "Fëanulda", "Fëapolda", "Fëaquilda",
			"Fëaranya", "Finca", "Finië", "Finwa", "Finya", "Handa", "Handassë",
			"Handë", "Handelë", "Hanquenta", "Hecil", "Hendusaila", "Heren",
			"Herenya", "Hórëa", "Hormë", "Hraia", "Hranga", "Hráva", "Húna",
			"Ilestel", "Ilvana", "Ilvanya", "Indo", "Intyalë", "Inwis", "Írë",
			"Ista", "Istima", "Istya", "Lacarëa", "Laita", "Lala", "Lala",
			"Laquet", "Lasta", "Laurëalassë", "Lehta", "Léra", "Lerina",
			"Lissë", "Lumba", "Lumna", "Mailë", "Mailëa", "Manë", "Maquet",
			"Maquetima", "Mára", "Maurëa", "Mausta", "Mel", "Méla", "Melda",
			"Melehta", "Melehtë", "Meletya", "Melima", "Melin", "Melmë",
			"Melwa", "Merca", "Merya", "Milca", "Milmë", "Mirwa", "Moina",
			"Naina", "Naira", "Nairë", "Naraca", "Nausë", "Nauta", "Nenalassë",
			"Nië", "Nielinya", "Nienainalë", "Nil", "Nilda", "Nilmë", "Nírë",
			"Níreär", "Nulda", "Nulla", "Ñóla", "Ñólë", "Ñolmë", "Ñolwë",
			"Ñorta", "Ñorto", "Ñúla", "Ñúlë", "Ñwalca", "Ñwalya", "Olca", "Órë",
			"Órenírë", "Ormë", "Orna", "Ossë", "Ossindo", "Pahta", "Panta",
			"Penya", "Quildossë", "Raica", "Raina", "Rainë", "Raita", "Ranya",
			"Ráva", "Remmórë", "Rúcima", "Rúcina", "Ruhta", "Rusca", "Rúthë",
			"Rúthëa", "Rúthëasercë", "Ruxa", "Saila", "Sailatië", "Sailelda",
			"Saira", "Sára", "Sarta", "Satar", "Satya", "Saucarya", "Sen",
			"Senda", "Senwa", "Senya", "Ser", "Sérë", "Ser", "Sincahonda",
			"Sinwa", "Sívë", "Sonda", "Tamna", "Tána", "Tanca", "Tára", "Taura",
			"Téna", "Téra", "Tercen", "Thanda", "Thanya", "Thorna", "Tielóra",
			"Tulca", "Tulcatië", "Túra", "Túrëa", "Úcar", "Úfárëa", "Ulca",
			"Ulco", "Úmëa", "Úna", "Urda", "Urtha", "Úthahtië", "Uxarë",
			"Varanda", "Varna", "Verca", "Verië", "Verya", "Vórima", "Vorindo",
			"Voronda", "Vorothanya", "Walda", "Walmë", "Walwistë", "Walya",
			"Wanwestel", "Wéra", "Wilda", "Wilwa", "Winima", "Yaiwë", "Yelwa",
			"Yérë", "Yesta",
			//quenya celestial
			"Alca", "Alcar", "Alcarin", "Alta", "Anarórë", "Andúnë", "Ára",
			"Árë", "Arin", "Arma", "Artuilë", "Aurë", "Cala", "Calairë",
			"Calassë", "Calima", "Calina", "Cú", "Eärcala", "Él", "Eldacala",
			"Élë", "Elen", "Elena", "Elennúmen", "Elenya", "Elenquelië",
			"Élquassë", "Elvëa", "Fairë", "Fanya", "Fanyarë", "Fëarillë",
			"Hala", "Hellë", "Histë", "Hó", "Huinë", "Huiva", "Ilca", "Ilma",
			"Ilwë", "Isilmë", "Íta", "Ita", "Itila", "Ixal", "Laimë", "Laira",
			"Laurë", "Lëo", "Lilómëa", "Ló", "Lómë", "Lómëa", "Lumba", "Lumbë",
			"Lumbulë", "Lúmë", "Lúna", "Mordo", "Mórë", "Muinungo", "Nuhuinë",
			"Nulla", "Ñalta", "Ñillë", "Ossehuinë", "Rillë", "Rilma", "Rilya",
			"Ringelen", "Sil", "Silda", "Silma", "Silmë", "Thinyë", "Tin",
			"Tinda", "Tindë", "Tindómë", "Tingilindë", "Tingilya", "Tintila",
			"Tintina", "Tinwë", "Undómë", "Ungo", "Ungossë", "Unuhuinë",
			"Winyára", "Yualë", "Yucalë",
			//quenya waether
			"Airehíthë", "Aireraumo", "Alaco", "Fána", "Helca", "Helcë",
			"Helyanwë", "Histëala", "Híthë", "Hithwë", "Hwesta", "Iluquinga",
			"Lossë", "Lumbo", "Lúrë", "Lúrëa", "Missë", "Mistë", "Niquë",
			"Niquis", "Nixë", "Olos", "Quildalaco", "Quildaraumo", "Raumo",
			"Raumolírë", "Rossë", "Thúlë", "Thúrë", "Wailë", "Wailima", "Waiwa",
			"Waiwë", "Wangwë",
			//quenya flora
			"Aicanassë", "Alalmë", "Alda", "Alenessë", "Aldinga", "Alma",
			"Altorno", "Cullassë", "Culuma", "Culumalda", "Eldasilquë",
			"Ercassë", "Erdë", "Escë", "Farnë", "Feren", "Ferinya", "Ferna",
			"Haldalótë", "Hwan", "Hwindë", "Indil", "Laima", "Laiquë", "Lalmë",
			"Lassë", "Laurorno", "Lávar", "Lavaralda", "Lepetta", "Lillassëa",
			"Lilótëa", "Linquë", "Lossë", "Lótë", "Lóth", "Lotsë", "Maldornë",
			"Malinornë", "Maltathar", "Nieninquë", "Nordo", "Olassë", "Olba",
			"Olótë", "Olva", "Ornë", "Ornél", "Orofarnë", "Pië", "Pirindë",
			"Pirnë", "Piucca", "Quëa", "Quildalótë", "Salquë", "Sulca",
			"Tathar", "Taurë", "Taurëa", "Taurina", "Táva", "Tavar", "Tavárëa",
			"Thánë", "Thara", "Thúriquessë", "Tuima", "Tussa", "Tyulussë",
			"Uilë", "Yáralda", "Yávë",
			//quenya fauna
			"Aiwë", "Alqua", "Ambalë", "Ammalë", "Andamunda", "Ango",
			"Angulócë", "Casar", "Cirincë", "Corco", "Cucua", "Fëalócë",
			"Fenumë", "Filit", "Hala", "Halatir", "Harma", "Hruo", "Hú", "Huan",
			"Huo", "Hyalma", "Laman", "Leuca", "Lingwë", "Lingwilócë",
			"Lirulin", "Lócë", "Maiwë", "Máma", "Mëo", "Morco", "Morilindë",
			"Mundo", "Nauco", "Naucon", "Norna", "Nyarro", "Ñarmo", "Ñaulë",
			"Ñauro", "Olombo", "Orco", "Pí", "Porocë", "Quácë", "Rá", "Ráca",
			"Rámalócë", "Rauca", "Ravennë", "Roa", "Rocco", "Ronya", "Rusco",
			"Ruscuitë", "Tambaro", "Thoron", "Tuilindo", "Ulundo", "Ungongarmo",
			"Ungwë", "Urco", "Urulócë", "Wán", "Wilin", "Wilwarin",
			"Wilwarindëa",
			//quenya occupation
			"Accar", "Ala", "Alta", "Ambassë", "Ampa", "Ara", "Arna", "Arossë",
			"Arhesto", "Atsa", "Aulë", "Auta", "Caima", "Calar", "Callo",
			"Calma", "Calpa", "Can", "Car", "Carasta", "Carma", "Carma",
			"Carmë", "Cassa", "Castol", "Cauma", "Cemnar", "Cenda", "Cesta",
			"Ceth", "Cilin", "Cilintilla", "Cilintír", "Cilinyul", "Círa",
			"Circa", "Cirya", "Coimas", "Col", "Comya", "Condo", "Cornë",
			"Coron", "Cundo", "Cundu", "Cúnë", "Cunta", "Cunya", "Curu",
			"Curulírë", "Curumaitë", "Curuni", "Curuvar", "Curwë", "Ecceth",
			"Ecet", "Ehtar", "Ehtë", "Ehtyar", "Endaquet", "Etelehta",
			"Falquan", "Ham", "Harna", "Harpa", "Hatal", "Hilya", "Hir",
			"Hloima", "Hloirë", "Hloirëa", "Hloita", "Hyalin", "Hyam", "Hyan",
			"Hyanda", "Hyar", "Hyar", "Ingólemo", "Ingolmo", "Lairë", "Lanat",
			"Lanë", "Lango", "Lannë", "Lanwa", "Lanya", "Lanya", "Lelya",
			"Lenda", "Lia", "Lia", "Líco", "Lícuma", "Lilta", "Linda",
			"Lindananda", "Lindalë", "Lindë", "Lir", "Lírë", "Lirilla", "Lirit",
			"Lúcë", "Luhta", "Luntë", "Macil", "Mahta", "Maica", "Manca",
			"Massa", "Massë", "Masta", "Masta", "Maxë", "Mesta", "Mista",
			"Mittanya", "Mól", "Mol", "Móro", "Móta", "Nac", "Nahta", "Nam",
			"Náma", "Namba", "Namba", "Narda", "Nasta", "Natsë", "Nav", "Nehta",
			"Nehta", "Netil", "Netya", "Neuma", "Nor", "Norta", "Núr", "Nútë",
			"Nyar", "Nyárë", "Nyarna", "Nyellë", "Nyel", "Ñanda", "Ñandë",
			"Ñandelë", "Ñandellë", "Ñúlë", "Ñúlelírë", "Ohta", "Ohtacar",
			"Ongwë", "Ontamo", "Ovesta", "Pano", "Panya", "Par", "Parma",
			"Pata", "Pelecco", "Pilin", "Quenta", "Quet", "Quildohtar",
			"Quinga", "Raima", "Raimë", "Raita", "Raiwë", "Ránë", "Ranya",
			"Ranya", "Rehta", "Rem", "Remba", "Rembë", "Remma", "Rer", "Rista",
			"Roimë", "Roita", "Róma", "Róma", "Romba", "Roquen", "Rúna",
			"Runando", "Russë", "Samno", "Sangwa", "Sarmë", "Sicil", "Taman",
			"Tamma", "Tamo", "Tancil", "Tan", "Tanta", "Tantila", "Tanwë",
			"Tautamo", "Tec", "Tecil", "Tercáno", "Thámo", "Thanyë", "Tir",
			"Tulya", "Tur", "Turma", "Tuv", "Tyal", "Tyalangan", "Tyalië",
			"Tyav", "Umbath", "Vanta", "Varnassë", "Varnë", "Varilë", "Varya",
			"Watharya", "Wérë", "Yulma", "Yur",
			//quenya place
			"Ailin", "Aicalë", "Aicassë", "Airë", "Amban", "Ambo", "Ampano",
			"Amun", "Ando", "Andúna", "Andúnë", "Arta", "Ataquë", "Avahaira",
			"Axa", "Capalinda", "Carassë", "Cectelë", "Celma", "Celu",
			"Celulinda", "Celumë", "Cilya", "Cirissë", "Coa", "Corda", "Corin",
			"Cormë", "Coron", "Cumbë", "Ëar", "Ëaron", "Eccaira", "Ectelë",
			"Ehtelë", "Enda", "Endë", "Endëa", "Enya", "Erumë", "Erúmëa",
			"Etsë", "Etsir", "Ettë", "Ettelë", "Ettelëa", "Falas", "Fallë",
			"Falma", "Falqua", "Fára", "Felca", "Felya", "Fenda", "Fenna",
			"Formenya", "Forna", "Fortë", "Hahta", "Haira", "Haiya", "Háya",
			"Hópa", "Hresta", "Hristil", "Hróna", "Hróta", "Hwindë",
			"Hyarmenya", "Hyarna", "Hyatsë", "Imbë", "Imbelossë", "Ingor",
			"Lantasírë", "Latta", "Linya", "Lóna", "Londë", "Luimë", "Maicorto",
			"Mar", "Martan", "Marto", "Men", "Minassë", "Mindë", "Mindo",
			"Mindon", "Mitya", "Nanda", "Nandë", "Nando", "Nanwë", "Nellë",
			"Nendë", "Nendë", "Níquetil", "Nortil", "Nucemen", "Nuinë",
			"Númenya", "Núna", "Nunalda", "Núra", "Opelë", "Oromar", "Oron",
			"Orotinga", "Orto", "Osto", "Palar", "Palúrë", "Panda", "Peler",
			"Pelo", "Quínë", "Ramba", "Ravanda", "Ráva", "Ravandalapsë",
			"Resta", "Ringwë", "Rómenya", "Rondo", "Rotto", "Sarnë", "Sarnië",
			"Sírë", "Siril", "Sirya", "Talan", "Taras", "Tarma", "Tarminas",
			"Telluma", "Telumë", "Thambë", "Tol", "Tumba", "Tumbo", "Tundo",
			"Ulundë", "Umbo", "Umpano", "Undumë", "Unquë", "Vaháya", "Wilma",
			"Wilya", "Winga", "Wingë", "Yána", "Yanta", "Yanwë", "Yatta",
			"Yáwë",
			//quenya elements
			"Airesarë", "Alas", "Anga", "Angaina", "Asto", "Calarus", "Calca",
			"Cemen", "Cemna", "Culo", "Eren", "Haldamírë", "Haldanárë",
			"Hyellë", "Ilsa", "Latucenda", "Litsë", "Malta", "Maril", "Marilla",
			"Marillindo", "Mírë", "Miril", "Nárë", "Nárescë", "Narya",
			"Nemmírë", "Nemmiril", "Nén", "Nyelecca", "Ñaltanárë", "Ondo",
			"Rauta", "Ruinë", "Ruivë", "Runda", "Rúnya", "Sar", "Sareär",
			"Sercë", "Silmë", "Telemna", "Telepsa", "Telpë", "Telpina", "Tinco",
			"Tyelpë", "Úr", "Urus", "Wista", "Yár", "Yúla",
			//Quenya People Names  Colors
			"Aira", "Carnë", "Culda", "Culina", "Cullo", "Culuina", "Ezella",
			"Fána", "Helwa", "Hithwa", "Hróva", "Ilin", "Laiqua", "Laiquaninwa",
			"Laurëa", "Lossëa", "Luina", "Luinë", "Luinincë", "Malda", "Malina",
			"Malwa", "Marya", "Mista", "Míthë", "Morna", "Narwa", "Nasar",
			"Néca", "Ninquë", "Ninquiraitë", "Ninquita", "Rusca", "Thinda",
			"Thindë", "Thinta", "Varnë", "Wenya", "Winda", "Windë", "Windya",
			"Winta",
			//Quenya People Names  Numbers
			"Er", "Erda", "Erëa", "Erinqua", "Eressë", "Eressëa", "Erya",
			"Métima", "Métimelda", "Telda", "Tella", "Tyel", "Tyelima",
			"Tyelma",
			//Quenya People Names  Miscellaneous
			"Ahya", "Aira", "Aista", "Aista", "Alanossë", "Aman", "Amanya",
			"Amarto", "Ambar", "Anna", "Anqualë", "Anta", "Anwa", "Arca",
			"Apacen", "Apairë", "Cáma", "Cammírë", "Canwa", "Cap", "Ceulë",
			"Ceura", "Ceuta", "Cordon", "Cuilë", "Cuina", "Ecya", "Ello",
			"Elmenda", "Emma", "Erca", "Esta", "Eterúna", "Fairë", "Felmë",
			"Fintalë", "Hampa", "Harma", "Harwë", "Himba", "Hlóna", "Hranga",
			"Húna", "Húta", "Inca", "Indemma", "Indyalmë", "Intya", "Lahta",
			"Láma", "Lámina", "Lemba", "Lemya", "Lerya", "Lís", "Loita", "Lor",
			"Lórë", "Lustamuina", "Maica", "Malo", "Mána", "Manar", "Mandë",
			"Manna", "Manta", "Manquenta", "Manya", "Mapta", "Maptalë",
			"Maranwë", "Marta", "Marto", "Mendë", "Meren", "Meryalë", "Millo",
			"Mírima", "Miulë", "Naiquet", "Naitë", "Naham", "Nahámë", "Nahta",
			"Nallama", "Nanwa", "Nassë", "Necel", "Nurta", "Nurtalë", "Ñalmë",
			"Ñona", "Ñwalma", "Ñwalmë", "Oia", "Oiala", "Oialëa", "Oira",
			"Olor", "Olorima", "Olos", "Olosta", "Onóna", "Orólos", "Ósanwë",
			"Pica", "Pirya", "Qualmë", "Quentalóra", "Quessë", "Quesset",
			"Quilda", "Quildë", "Quildolor", "Ráma", "Rama", "Ráta", "Rávë",
			"Rávëa", "Raxë", "Sáma", "Sana", "Sanwë", "Sanwecenda", "Síma",
			"Thangië", "Thanya", "Thelma", "Tixë", "Tó", "Tulco", "Tulta",
			"Túrë", "Umbar", "Ungwalë", "Unqualë", "Usquë", "Vórëa",
			"Vorondelda", "Voronwa", "Wanwa", "Wanya", "Wénëa", "Wil", "Wirnë",
			"Wirya", "Wista", "Yaimë", "Yaimëa", "Yal", "Yalmë", "Yello",
			//exilic people names personality
			"Aica", "Aeg", "Alassë", "Glass", "Alassindo", "Glassind", "Alima",
			"Alu", "Alma", "Galu", "Almarë", "Galu", "Almárëa", "Alwed", "Alya",
			"Alwed", "Alya", "Elia", "Aranya", "Ranui", "Arata", "Raud",
			"Arata", "Arod", "Aravalya", "Araval", "Arta", "Arth", "Asëa",
			"Athe", "Astar", "Astor", "Asya", "Eitha", "Cánë", "Caun", "Canya",
			"Cand", "Cotto", "Coth", "Cotumo", "Cûd", "Cotya", "Cothui",
			"Curulambë", "Curulam", "Estel", "Estel", "Faica", "Faeg", "Faila",
			"Fael", "Fárëa", "Fâr", "Fëalassëa", "Fëalas", "Finca", "Finc",
			"Finwa", "Find", "Finya", "Find", "Handa", "Hand", "Handassë",
			"Hannas", "Handë", "Hannas", "Handelë", "Hannas", "Hecil", "Eglan",
			"Hendusaila", "Henthael", "Hraia", "Rhae", "Hranga", "Rhanc",
			"Hráva", "Rhaw", "Indo", "Ind", "Írë", "Îr", "Ista", "Ista", "Ista",
			"Ist", "Istima", "Istui", "Istya", "Ist", "Laita", "Egleria",
			"Lala", "Lal", "Lasta", "Lasta", "Laurëalassë", "Glorlas", "Lehta",
			"Lain", "Lumba", "Lom", "Mailë", "Mael", "Mailëa", "Maelui", "Mára",
			"Maer", "Márafairë", "Marfaer", "Márafëa", "Marfaer", "Maurëa",
			"Bórui", "Mel", "Mel", "Méla", "Milui", "Melda", "Mell", "Melehta",
			"Beleg", "Meletya", "Beleg", "Melima", "Melui", "Melin", "Mell",
			"Melmë", "Meleth", "Melwa", "Melui", "Merca", "Bregol", "Merya",
			"Meren", "Milca", "Melch", "Moina", "Muin", "Naira", "Naer",
			"Nairë", "Naergon", "Nausë", "Nauth", "Nauta", "Naud", "Nenalassë",
			"Nenglas", "Nië", "Nîn", "Nielinya", "Nilin", "Nienainalë",
			"Nínaergon", "Nírë", "Nîr", "Níreärë", "Nírëar", "Nóla", "Goll",
			"Nólë", "Gûl", "Nolmë", "Gûl", "Nolwë", "Gûl", "Norta", "Gortheb",
			"Norto", "Goroth", "Nulda", "Dolen", "Nuldafairë", "Dolefaer",
			"Nuldafëa", "Dolefaer", "Núlë", "Gûl", "Nulla", "Dolen", "Olca",
			"Ogol", "Órë", "Gûr", "Órenírë", "Gurnir", "Ossë", "Gost",
			"Ossindo", "Gostind", "Panta", "Pant", "Poldafairë", "Belfaer",
			"Poldafëa", "Belfaer", "Quildafairë", "Dinefaer", "Quildafëa",
			"Dinefaer", "Quildossë", "Dinengost", "Raica", "Raeg", "Raina",
			"Raen", "Ranya", "Ranui", "Ranyafairë", "Ranuifaer", "Ranyafëa",
			"Ranuifaer", "Remmórë", "Remmur", "Rusca", "Rúthui", "Rúsë", "Rûth",
			"Rúsëa", "Rúthui", "Rúsëasercë", "Ruthuihereg", "Ruxa", "Rúthui",
			"Saila", "Sael", "Sailelda", "Saeleledh", "Saira", "Sael", "Sanda",
			"Thand", "Sára", "Saer", "Sarta", "Sador", "Satar", "Sadar", "Sérë",
			"Sîdh", "Ser", "Ser", "Sorna", "Thorn", "Taura", "Taur", "Téna",
			"Taer", "Téra", "Taer", "Tulca", "Tolog", "Túra", "Taur", "Túrëa",
			"Túrui", "Úfárëa", "Úfarn", "Ulca", "Ogol", "Ulco", "Ogol", "Úmëa",
			"Ûm", "Ursa", "Rûth", "Úsahtië", "Úthaes", "Úsaila", "Úhael",
			"Varna", "Barn", "Verca", "Braig", "Verië", "Berenas", "Verya",
			"Beren", "Vinima", "Gwain", "Vorindo", "Borind", "Voronda", "Boron",
			"Yaiwë", "Iaew", "Yelwa", "Delu", "Yérë", "Îr",
			//Adunaic names
			"Ar", "Lômi", "Nimir", "Toda", "Zimra", "Gimil", "Nilû", "Urî",
			"Azru", "Adûn", "Lômi", "Gimil", "Azra", "Pharâz", "Adûna",
			"Saptha", "Zôr", "Narû", "Azru", "Dolgu", "Îr", "Abra", "Arnu",
			"Avalo", "Azgar", "Balka", "Gimil", "Karba", "Minil", "Nilû",
			"Nimir", "Tamar", "Ûrî", "Zadna", "Abrazân", "Aphanu", "Azru",
			"Bel", "Gimil", "Sakal", "Nimir", "Pharaz", "Zimra", "Abra",
			"Adûna", "Aglar", "Arna", "Arnu", "Avradi", "Azul", "Balak",
			"Bawab", "Gimil", "Nimir", "Sakal", "Sapthan", "Tarîk", "Ûrî",
			"Zôr", "Zimir", "Azru", "Rôth", "Shakal", "Aglar", "Dolgu", "Gimil",
			"Pharaz",
			// Woodelven People Names  Physical Attributes
			"Agarwen", "Agor", "Alfirin", "And", "Angol", "Anu", "Auth", "Bain",
			"Bainthaur", "Ballin", "Baralin", "Bel", "Beleg", "Bornif", "Brass",
			"Brui", "Brûn", "Cadu", "Cadwor", "Caun", "Cel", "Celeb", "Celeg",
			"Cîw", "Colfind", "Dair", "Dínen", "Eden", "Esgal", "Esgar",
			"Estent", "Fân", "Fang", "Fast", "Faug", "Fim", "Gamp", "Gem",
			"Gern", "Glîn", "Gôd", "Gôr", "Gwain", "Gwass", "Gwen", "Hall",
			"Harn", "Haru", "Hell", "Helch", "Heleth", "Helf", "Him", "Hîw",
			"Iaur", "Ingem", "Inu", "Iphant", "Lanc", "Land", "Laug", "Leb",
			"Legol", "Lest", "Lhain", "Lhew", "Lhind", "Lom", "Long", "Lost",
			"Mai", "Malfind", "Maw", "Mecheneb", "Med", "Mel", "Mîw",
			"Naruthir", "Naud", "Neth", "Nind", "Norcheneb", "Noruinif",
			"Orchal", "Pant", "Parch", "Path", "Perchalad", "Pigen", "Pôm",
			"Puig", "Reg", "Ren", "Ring", "Rivalt", "Sain", "Selcheneb", "Tâch",
			"Targ", "Telphind", "Ten", "Ter", "Thent", "Thiad", "Thirrest",
			"Thron", "Thúren", "Tithen", "Trêw", "Trewath", "Tû", "Tûg", "Tund",
			"Ûr", "Usp",
			// Woodelven People Names  Personality
			"Acharn", "Achas", "Air", "Alag", "Alhel", "Amdir", "Âr", "Arhel",
			"Arn", "Arod", "Arth", "Asgar", "Avorn", "Baissel", "Balch", "Bara",
			"Baug", "Baul", "Baur", "Beren", "Bereth", "Bragol", "Braig",
			"Brand", "Brêg", "Breged", "Bregol", "Bronwe", "Cand", "Caun",
			"Coru", "Cost", "Coth", "Curu", "Dair", "Dairdhel", "Del",
			"Deldhinen", "Deleb", "Delgaran", "Delos", "Delu", "Dem", "Dûr",
			"Edlenn", "Edraith", "Eglan", "Elnin", "Estel", "Estelmist", "Far",
			"Feg", "Fel", "Galu", "Galuchin", "Ge", "Gel", "Gelinnas", "Gellam",
			"Gellui", "Ger", "Girith", "Glass", "Goe", "Goeol", "Goll",
			"Golwen", "Gorf", "Gorn", "Gorog", "Goroth", "Gorth", "Gortheb",
			"Gost", "Gûd", "Gûr", "Gurveleg", "Gwend", "Hal", "Hand", "Hethu",
			"Him", "Horn", "Hûl", "Hûr", "Hwind", "Idhren", "Iest", "Iew",
			"Inc", "Ind", "Îr", "Istui", "Lain", "Lamen", "Lind", "Mel", "Mel",
			"Melch", "Melui", "Men", "Mer", "Meren", "Mîl", "Milui", "Mist",
			"Muil", "Muin", "Ner", "Nîd", "Nîn", "Nîr", "Nûr", "Olg", "Orchal",
			"Reg", "Remlas", "Rhaw", "Rûth", "Rúthlegol", "Sel", "Ser",
			"Seregruth", "Sîdh", "Sírdhem", "Thala", "Thalawest", "Thand",
			"Thangur", "Thaur", "Thaw", "Thurelost", "Um", "Úthes", "Ýridhren",
			// Woodelven People Names  Celestial
			"Aduial", "Aglar", "Aglareb", "Annúngil", "Aur", "Calad",
			"Calithil", "Celair", "Claur", "Dair", "Daum", "Daw", "Dû", "Dûm",
			"Dûr", "Êl", "Elchim", "Ell", "Esgalwath", "Fuin", "Gail", "Gal",
			"Galad", "Gel", "Gîl", "Glaur", "Glaw", "Glawar", "Gorfuin",
			"Gwath", "Ladrengil", "Lim", "Maur", "Môr", "Orel", "Palanel",
			"Pelinel", "Silef", "Thîn", "Tim", "Timbelin", "Tindum",
			// Woodelven People Names  Flora
			"Alfirin", "Belegorn", "Breth", "Cullas", "Dínelloth", "Dorn",
			"Dumloth", "Êg", "Eglos", "Elanor", "Erdh", "Ereg", "Esgar", "Fêr",
			"Galadh", "Galas", "Gilorn", "Golf", "Gwastar", "Halloth", "Iau",
			"Iorthon", "Lalf", "Lass", "Linnorn", "Loth", "Lumorn", "Mallos",
			"Meril", "Mormeril", "Nínim", "Nirorn", "Orn", "Pelillas",
			"Rhossolas", "Salab", "Solch", "Tathar", "Telvolas", "Thâr", "Thôn",
			"Thond", "Toss", "Tui", "Tulus", "Uilos", "Úlloth",
			// Woodelven People Names  Fauna
			"Alph", "Amlug", "Aras", "Corch", "Craban", "Cugu", "Draug",
			"Dúlind", "Emlin", "Ew", "Fileg", "Garaf", "Gaul", "Gaur", "Gawad",
			"Graw", "Gwaun", "Gwilwering", "Hâl", "Half", "Heledir", "Hû",
			"Lavan", "Lhing", "Lim", "Lobor", "Lûg", "Medlí", "Merilin", "Mund",
			"Raw", "Roch", "Rusc", "Rŷn", "Tavor", "Thorn", "Tuilind", "Úan",
			"Ulund", "Ûn", "Ungol",
			// Woodelven People Names  Occupation
			"Aith", "Amath", "Angol", "Aradhel", "Arahel", "Arrad", "Auth",
			"Calar", "Calph", "Camen", "Cellind", "Cû", "Curuler", "Dagor",
			"Dam", "Daug", "Ecthel", "Erist", "Gangel", "Gaud", "Gler", "Glew",
			"Glîr", "Glûdh", "Gowest", "Grond", "Gûl", "Guldur", "Gwedh",
			"Habad", "Hâdh", "Hadlath", "Ham", "Harn", "Hast", "Hathol",
			"Haust", "Ianu", "Iorist", "Ist", "Lain", "Lang", "Legolang",
			"Lend", "Ler", "Lhê", "Lingul", "Lîr", "Lûth", "Magol", "Maias",
			"Meth", "Mist", "Morgul", "Mûl", "Nath", "Nestad", "Ningangel",
			"Parf", "Peng", "Pent", "Peth", "Rain", "Ref", "Rem", "Rî", "Rîn",
			"Rîs", "Rom", "Rui", "Tegol", "Thand",
			// Woodelven People Names  Place
			"Adab", "Aglon", "Amon", "Amrûn", "Annon", "Annui", "Annûn",
			"Balrant", "Band", "Bar", "Barad", "Both", "Cai", "Cail", "Caras",
			"Celon", "Cew", "Cîl", "Dath", "Dôl", "Duil", "Duinen", "Duirro",
			"Dúven", "Echad", "El", "Ened", "Ephel", "Eru", "Eryn", "Esgar",
			"Estolad", "Ethir", "Falch", "Fela", "Fend", "Forn", "Forod",
			"Forven", "Fuir", "Gador", "Garth", "Gas", "Gath", "Gathrod", "Gaw",
			"Gobel", "Gorthad", "Groth", "Harad", "Haradren", "Harn", "Haudh",
			"He", "Henneth", "Hered", "Heron", "Iâ", "Iach", "Iant", "Iau",
			"Iaun", "Iôl", "Lad", "Lant", "Lanthir", "Lîn", "Lô", "Loeg",
			"Lorn", "Lossam", "Megorod", "Men", "Minas", "Mindon", "Nadhor",
			"Nand", "Oll", "Orod", "Pâd", "Parth", "Pel", "Râd", "Ram", "Rant",
			"Raw", "Rhovan", "Rim", "Sîr", "Talath", "Talf", "Taur", "Thalos",
			"Tharbad", "Tund", "Ŷr",
			// Woodelven People Names  Elements
			"Agar", "Amar", "Ang", "Bril", "Calemir", "Caranor", "Ce", "Cef",
			"Côl", "Dinthalos", "Eglos", "Eiliant", "Esgalnor", "Faun", "Gond",
			"Gwau", "Gwelo", "Gweren", "Gwilith", "Gwing", "Heledh", "Heleg",
			"Hith", "Hither", "Iâr", "Iûl", "Ivor", "Lach", "Limp", "Lith",
			"Lithui", "Loen", "Loss", "Lossen", "Malt", "Midh", "Mîr",
			"Miresgal", "Mith", "Mithril", "Naur", "Nemir", "Nen", "Nengel",
			"Nîd", "Nîn", "Norawarth", "Norgalad", "Rust", "Sarn", "Sereg",
			"Sew", "Sûl", "Taw", "Telf", "Tinc", "Tint", "Tinu", "Ûr", "Usp",
			// Woodelven People Names  Colors
			"Arn", "Aros", "Baran", "Born", "Calen", "Caran", "Col", "Dol",
			"Elu", "Fain", "Fan", "Ger", "Glân", "Glos", "Gruin", "Gwên", "Leg",
			"Luin", "Lum", "Maidh", "Malen", "Malu", "Mith", "Morn", "Naru",
			"Nimp", "Rhosg", "Ruin", "Thind", "Uilos",
			// Female Woodelven Names  Numbers
			"Er", "Main", "Minai", "Edwen", "Abonnen", "Meth", "Methed",
			"Methen", "Medui",
			// Woodelven People Names  Miscellaneous
			"Ablad", "Amarth", "Amarthedhel", "Angwedh", "Ant", "Avornedhel",
			"Barad", "Baudh", "Bronad", "Carangur", "Cîl", "Cîr", "Ech",
			"Echui", "Eg", "Egnas", "Erch", "Glam", "Glamor", "Glamren",
			"Glavrol", "Glî", "Gûr", "Gurth", "Guruth", "Gwedh", "Gwî", "Gwîn",
			"Hew", "Ial", "Îdh", "Laig", "Lant", "Leithian", "Lhîw", "Lhos",
			"Lif", "Mâl", "Manadh", "Megor", "Ment", "Nardh", "Nell", "Nîdh",
			"Ôl", "Oldhinen", "Óleryd", "Peg", "Pess", "Raph", "Ravon", "Ren",
			"Rhoss", "Rîn", "Tûr", "Uir", "Uireb",
			// Sindarin People Names  Physical Attributes
			"Agarwaen", "Agor", "And", "Angol", "Anu", "Auth", "Bain",
			"Bainthaur", "Ballin", "Baralin", "Beleg", "Belt", "Brass", "Brui",
			"Brûn", "Cadu", "Cadwor", "Cael", "Caeleb", "Caraphind", "Carandol",
			"Celeg", "Celephind", "Cîw", "Colfind", "Cûn", "Daer", "Dínen",
			"Duvain", "Eden", "Esgal", "Estent", "Fân", "Fang", "Fast", "Faug",
			"Fim", "Fingaer", "Glingaer", "Gamp", "Gem", "Gern", "Glîn",
			"Gwaen", "Gwain", "Gwas", "Gwaur", "Hall", "Harn", "Haru", "Helf",
			"Hell", "Heleth", "Him", "Hîw", "Iaur", "Ingem", "Inu", "Iphant",
			"Laeb", "Lagor", "Lanc", "Land", "Laug", "Lest", "Lhaew", "Lhain",
			"Lhind", "Lom", "Long", "Lost", "Mad", "Mae", "Maecheneb", "Maed",
			"Mael", "Malfind", "Maw", "Mîw", "Morfind", "Naud", "Nend", "Neth",
			"Niben", "Nimp", "Nind", "Orchal", "Osp", "Pant", "Parch", "Path",
			"Perchalad", "Pigen", "Puig", "Raeg", "Raen", "Ring", "Riros",
			"Rivalt", "Rivorn", "Ross", "Rothruin", "Rûdh", "Ruindol", "Sain",
			"Taen", "Taer", "Tharn", "Thent", "Thirist", "Thosta", "Thurin",
			"Tithen", "Tond", "Trîw", "Triwath", "Tû", "Tûg", "Ûr",
			// Sindarin People Names  Personality
			"Achar", "Acharn", "Achas", "Aen", "Aer", "Alag", "Amdir", "Aníra",
			"Âr", "Aradhel", "Arahael", "Arn", "Arod", "Arth", "Avorn",
			"Awartha", "Baingol", "Balch", "Bara", "Bartha", "Baug", "Baul",
			"Baur", "Belegur", "Beren", "Beria", "Bertha", "Bornif", "Bragol",
			"Braig", "Brand", "Brêg", "Breged", "Bregol", "Bronwe", "Cand",
			"Caun", "Coru", "Cost", "Coth", "Curu", "Daedhel", "Daer", "Def",
			"Del", "Deldhin", "Deleb", "Delgaran", "Delos", "Delu", "Dem",
			"Dew", "Dreg", "Dûr", "Edlen", "Edraith", "Eglan", "Egleria",
			"Eitha", "Erist", "Estel", "Faeg", "Fael", "Far", "Feira", "Gae",
			"Gaer", "Galu", "Gelinnas", "Gell", "Gellam", "Gellui", "Gir",
			"Girith", "Gladh", "Glass", "Glavra", "Goe", "Goeol", "Golwen",
			"Goll", "Gorf", "Gorn", "Gorog", "Goroth", "Gorth", "Gortheb",
			"Gost", "Gosta", "Groga", "Gruitha", "Gûd", "Gûr", "Gurgaran",
			"Gwend", "Gweria", "Hall", "Hand", "Hartha", "Henia", "Heria",
			"Him", "Hinnor", "Hissael", "Horn", "Hortha", "Hûl", "Hûr", "Hwind",
			"Iaew", "Ídha", "Ídhra", "Idhren", "Iest", "Inc", "Ind", "Îr",
			"Ist", "Ista", "Istui", "Lagorúth", "Lain", "Lamaen", "Lend",
			"Mael", "Maen", "Maer", "Melch", "Mell", "Melui", "Meren", "Mîl",
			"Milui", "Mist", "Mista", "Muil", "Muin", "Naegra", "Naer",
			"Naruthir", "Nautha", "Neitha", "Nîd", "Nîn", "Nîr", "Noruinif",
			"Nûr", "Ogol", "Orchal", "Pel", "Presta", "Raeg", "Remlas", "Rhaw",
			"Rûth", "Ruthra", "Sael", "Saer", "Seregruth", "Sîdh", "Sírdhem",
			"Tara", "Thala", "Thalawest", "Thand", "Thangur", "Thaur", "Thaw",
			"Theria", "Theria", "Thurilost", "Thurin", "Trasta", "Tûr", "Úhael",
			"Um", "Úthaes", "Ýridhren",
			// Sindarin People Names  Celestial
			"Aduial", "Aglar", "Aglareb", "Annúngil", "Aur", "Calad",
			"Caledhel", "Calithil", "Celair", "Claur", "Dae", "Daw", "Dû", "Êl",
			"Esgalwath", "Fuin", "Gael", "Gal", "Gail", "Gal", "Galad", "Glaur",
			"Glaw", "Glawar", "Gorfuin", "Gwathra", "Haerel", "Himel",
			"Ladrengil", "Lim", "Lothuial", "Maur", "Míria", "Môr", "Orel",
			"Pelinel", "Pelingil", "Rîl", "Síla", "Silevren", "Thilia", "Thîn",
			"Tinna", "Tinnu", "Tinu", "Uial",
			// Sindarin People Names  Weather
			"Aeglos", "Alagos", "Dinalagos", "Eiliant", "Fain", "Faun",
			"Gwaeren", "Gwaew", "Helch", "Heleg", "Hith", "Hithfaer", "Hithu",
			"Hwest", "Loss", "Lossen", "Midh", "Mith", "Ninniach", "Nórui",
			"Ross", "Sûl",
			// Sindarin People Names  Flora
			"Aeglos", "Alfirin", "Belegorn", "Brethil", "Celeblas", "Cullass",
			"Dílloth", "Doron", "Êg", "Elanor", "Eredh", "Ereg", "Fêr",
			"Gaeruil", "Galadh", "Galas", "Galenas", "Gilorn", "Golf",
			"Gwastar", "Halloth", "Iau", "Iorthon", "Lalf", "Lass", "Loth",
			"Laerorn", "Lumorn", "Mallos", "Meril", "Mormeril", "Nínim",
			"Nirorn", "Orn", "Pelilas", "Rhossolas", "Salab", "Solch", "Tathar",
			"Thâr", "Thôn", "Thond", "Toss", "Tuiw", "Tulus", "Uil", "Uilos",
			"Úlloth",
			// Sindarin People Names  Fauna
			"Aew", "Aewen", "Alph", "Amlug", "Aras", "Corch", "Craban", "Cugu",
			"Daedhrog", "Draug", "Dúlind", "Emlin", "Fileg", "Garaf", "Gaul",
			"Gaur", "Gawad", "Graw", "Gwael", "Gwaun", "Gwilwileth", "Hâl",
			"Half", "Heledir", "Hû", "Lavan", "Lhing", "Lim", "Limlug", "Lobor",
			"Lûg", "Maew", "Medlí", "Medlin", "Merilin", "Mund", "Mŷl", "Raw",
			"Roch", "Rusc", "Rŷn", "Tavor", "Thôr", "Tuilind", "Úan", "Ulund",
			"Ûn", "Ungol",
			// Sindarin People Names  Occupation
			"Adertha", "Adleg", "Aith", "Amath", "Amartha", "Angol", "Aphada",
			"Aphed", "Auth", "Banga", "Basta", "Cair", "Calar", "Calph",
			"Camaen", "Can", "Carva", "Cellin", "Cen", "Critha", "Cû",
			"Curulaer", "Dag", "Dam", "Damma", "Daug", "Delia", "Doltha",
			"Draf", "Dringa", "Echad", "Ecthel", "Eitha", "Elia", "Ertha",
			"Esta", "Fara", "Feria", "Gad", "Gala", "Ganna", "Gannel", "Gaud",
			"Glaer", "Glaew", "Glir", "Glîr", "Glûdh", "Gonod", "Gowest",
			"Grond", "Gûl", "Guldur", "Gwaedh", "Gwedh", "Gwesta", "Habad",
			"Had", "Hâdh", "Hadlath", "Ham", "Harn", "Harna", "Hast", "Hasta",
			"Hathol", "Haust", "Heb", "Ialla", "Ianu", "Iorist", "Iuitha",
			"Laer", "Laergul", "Lain", "Lang", "Lasta", "Leitha", "Lend", "Lhê",
			"Linna", "Lîr", "Liria", "Lûth", "Lútha", "Maeth", "Maetha",
			"Maetha", "Magol", "Maeas", "Mist", "Morgul", "Muda", "Mûl",
			"Nalla", "Nara", "Nath", "Nedia", "Nell", "Nella", "Nesta", "Nod",
			"Nor", "Northa", "Orthel", "Orthor", "Osgar", "Pada", "Padra",
			"Parf", "Ped", "Peng", "Penia", "Pent", "Peth", "Rada", "Raeda",
			"Raef", "Rain", "Raitha", "Ran", "Redh", "Rem", "Renia", "Revia",
			"Rî", "Rîn", "Rista", "Rom", "Rosta", "Rui", "Sog", "Suila",
			"Taetha", "Tangada", "Tegol", "Telia", "Teitha", "Thand", "Thora",
			"Tir", "Toba", "Tog", "Toltha", "Tortha", "Trenar", "Trevad",
			//Sindarin People Names  Place
			"Adab", "Aear", "Aearon", "Ael", "Aer", "Aglon", "Amon", "Amrûn",
			"Annon", "Annui", "Annûn", "Balrant", "Band", "Bar", "Barad",
			"Both", "Caew", "Cai", "Cail", "Calaer", "Caras", "Cast", "Celon",
			"Cîl", "Côf", "Dath", "Dôl", "Duin", "Duinen", "Duirro", "Dúven",
			"Echad", "Ened", "Ephel", "Eru", "Eryn", "Esgar", "Estolad",
			"Ethir", "Falas", "Falch", "Faur", "Fela", "Fend", "Forn", "Forod",
			"Forven", "Fuir", "Gador", "Gaear", "Gaer", "Garth", "Gas", "Gath",
			"Gathrod", "Gaw", "Gobel", "Gorthad", "Groth", "Hae", "Haered",
			"Haeron", "Harad", "Haradren", "Harn", "Haudh", "Henneth",
			"Hithaer", "Hûb", "Iâ", "Iach", "Iant", "Iau", "Iaun", "Iôl", "Lad",
			"Lant", "Lanthir", "Lîn", "Lô", "Loeg", "Lorn", "Lossam",
			"Maegorod", "Men", "Minas", "Mindon", "Nadhor", "Nan", "Ninael",
			"Ningaear", "Oll", "Óleryd", "Orod", "Pâd", "Parth", "Pel", "Râd",
			"Ram", "Rant", "Raw", "Rhovan", "Rim", "Sîr", "Talath", "Talf",
			"Taur", "Tharbad", "Tol", "Tund", "Ŷr",
			//Sindarin People Names  Colors
			"Baran", "Born", "Bornif", "Calen", "Caran", "Coll", "Doll", "Dûr",
			"Elu", "Faen", "Fain", "Gaer", "Glân", "Gloss", "Gruin", "Gwath",
			"Laeg", "Luin", "Lum", "Maidh", "Malen", "Malu", "Mith", "Morn",
			"Naru", "Nimp", "Rhosg", "Ruin", "Thind", "Uilos",
			//Sindarin People Names  Numbers
			"Main", "Er", "Minai", "Edwen", "Abonnen", "Meth", "Methed",
			"Methen", "Medui",
			//Sindarin People Names  Elements
			"Agar", "Amar", "Ang", "Cae", "Calemir", "Caranor", "Cef", "Celeb",
			"Celebren", "Ceven", "Côl", "Esgalnor", "Gond", "Gwelu", "Gwilith",
			"Gwing", "Heledh", "Iâr", "Iûl", "Ivor", "Lach", "Lacha", "Limp",
			"Lith", "Lithui", "Loen", "Malt", "Mîr", "Míresgal", "Mithril",
			"Naur", "Nemir", "Nen", "Nengel", "Nîd", "Nîn", "Norawarth",
			"Norgalad", "Osp", "Rust", "Saew", "Sarn", "Sereg", "Silef", "Taw",
			"Tinc", "Tint", "Tinu", "Ûr",
			//Sindarin People Names  Miscellaneous
			"Ablad", "Aeg", "Amarth", "Amarthedhel", "Angwedh", "Ant", "Arrad",
			"Baudh", "Brenia", "Brona", "Bronad", "Cab", "Cîl", "Cîr", "Ech",
			"Echui", "Egnas", "Erch", "Glam", "Glamor", "Glamren", "Glavrol",
			"Glî", "Gûr", "Gurth", "Guruth", "Gwedh", "Gwî", "Haew", "Hwinia",
			"Ial", "Îdh", "Laba", "Laeg", "Lant", "Leithian", "Lhîw", "Lhoss",
			"Lif", "Loda", "Mâl", "Manadh", "Megor", "Ment", "Nag", "Narcha",
			"Nardh", "Nartha", "Nasta", "Nîdh", "Ôl", "Oldhin", "Oltha", "Peg",
			"Raen", "Raph", "Ravon", "Rib", "Rîn", "Ritha", "Than", "Uir",
			"Uireb",
			//BlackSpeechNames
			"Ash", "Bagronk", "Búbhosh", "Búrz", "Dug", "Ghâsh", "Glob", "Gûl",
			"Olog", "Push", "Sharkû", "Snaga" };

	mNamePrefix.assign(namePrefix,
		namePrefix + sizeof(namePrefix) / sizeof(namePrefix[0]));

	std::string nameSuffix[] = {
			//dwarfish
			"aim", "a", "ain", "ala", "ak", "ana", "ar", "ip", "i", "ia", "ur",
			"ona", "im", "ila", "in", "ina", "or", "ola", "o", "on",
			//elvish
			"ael", "aer", "aera", "aias", "aia", "ah", "aha", "aith", "aira",
			"al", "ala", "la", "lae", "llae", "ali", "am", "ama", "an", "ana",
			"a", "ani", "uanna", "ar", "ara", "ra", "ari", "ri", "aro", "ro",
			"as", "ash", "sah", "ath", "avel", "brar", "abrar", "ibrar", "dar",
			"adar", "odar", "deth", "eath", "eth", "dre", "drim", "drimme",
			"udrim", "dul", "ean", "el", "ele", "ela", "emar", "en", "er",
			"erl", "ern", "ess", "esti", "evar", "fel", "afel", "efel", "hal",
			"ahal", "ihal", "har", "ihar", "uhar", "hel", "ahel", "ihel", "ian",
			"ianna", "ia", "ii", "ion", "iat", "ik", "il", "iel", "ila", "lie",
			"im", "in", "inar", "ine", "ir", "ira", "ire", "is", "iss", "ist",
			"ith", "lath", "lith", "lyth", "kash", "ashk", "okash", "ki", "lan",
			"lanna", "lean", "olan", "ola", "lam", "ilam", "ulam", "lar",
			"lirr", "las", "lian", "lia", "lis", "elis", "lys", "ellon", "lyn",
			"llinn", "lihn", "mah", "ma", "mahs", "mil", "imil", "umil", "mus",
			"nal", "inal", "onal", "nes", "nin", "nine", "nyn", "nis", "anis",
			"oth", "othi", "que", "quis", "rah", "rae", "raee", "rad", "rahd",
			"rail", "ria", "aral", "ral", "ryl", "ran", "re", "reen", "reth",
			"rath", "ro", "ri", "ron", "ruil", "aruil", "eruil", "sal", "isal",
			"sali", "san", "sar", "asar", "isar", "sel", "asel", "isel", "sha",
			"she", "shor", "spar", "tae", "itae", "tas", "itas", "ten", "iten",
			"thal", "tha", "ethal", "etha", "thar", "ethar", "ithar", "ther",
			"ather", "thir", "thi", "ethil", "thil", "thus", "thas", "aethus",
			"aethas", "ti", "eti", "til", "tril", "tria", "atri", "atril",
			"atria", "ual", "lua", "uath", "luth", "uth", "us", "ua", "van",
			"vanna", "var", "vara", "avar", "avara", "vain", "avain", "via",
			"avia", "vin", "avin", "wyn", "ya", "yr", "yn", "yth", "zair",
			"zara", "azair", "ezara",
			//men
			"ferth", "helm", "laf", "wald", "wine", "wulf", "flaed", "leofu",
			"bur", "wen", "gifu", "waru", "swith", "randir", "thelion", "dor",
			"born ", "uil", "dal", "ieth", "iel", "rian", "wing", "uial", "los",
			"uilos",
			//hobbits
			"acar", "gard", "fast", "wise", "mond",
			//more elvish
			"gon", "wë", "anor", "edan", "iel", "las", "wen", "rond", "indal",
			"anna", "na", "ien", "mir", "ndil", "orn", "sar", "ion", "riel",
			"ros", "gund", "ambar", "dir", "dur", "wing", "bereth", "rohir",
			//quenya names
			"ë", "ië", "ien", "issë", "indë", "llë", "më", "rë", "wendë",
			"níssë", "yeldë", "iel", "o", "on", "no", "indo", "mo", "ro", "nér",
			"yondo", "ion", "", "r", "quen", "wë", "nil", "ndil", "nur", "ndur",
			//ardunaic names
			"phazel", "phel", "rôth", "phêr", "îth", "zimril", "arî", "inzil",
			"indil", "eth", "bên", "zagar", "pân", "zîr", "bêl", "magân", "zôr",
			"thôr", "ôn", "thon", "zimir", "bel", "ân", "khôr", "îr", "gimil",
			"pharaz", "balak",
			//woodelven names
			"eth", "ien", "iell", "iel", "sell", "gwen", "neth", "dîs", "dess",
			"nîth", "thêl", "bess", "on", "iôn", "ion", "der", "dîr", "benn",
			"tôr", "hawn", "hanar", "pen",
			//sindarin names
			"eth", "el", "il", "ien", "iell", "iel", "ril", "sell", "gwend",
			"neth", "dîs", "dess", "bess", "nîth", "thêl", "on", "ron", "iôn",
			"ion", "daer", "dîr", "bend", "tôr", "hawn", "hanar", "or", "pen",
			//BlackSpeechNames
			"olog", "uruk", "um", "um", "búrz", "búrz", "uk", "um", "búbhosh",
			"búrz", "um", "ghâsh", "búrz", "dug", "búrz", "búrz", "um", "ghâsh",
			"gûl", "sharkû", "búrz" };

	mNameSuffix.assign(nameSuffix,
		nameSuffix + sizeof(nameSuffix) / sizeof(nameSuffix[0]));

	std::string nameStems[] = { "", "adur", "aes", "anim", "apoll", "imac",
			"educ", "equis", "extr", "guius", "hann", "equi", "amora", "hum",
			"iace", "ille", "inept", "iuv", "obe", "ocul", "orbis" };

	mNameStems.assign(nameStems,
		nameStems + sizeof(nameStems) / sizeof(nameStems[0]));
}

std::string NameGenerator::generateFirstName() {
	std::string newName;
	int number = Randomness::getSingleton()->nextUnifPosInt(0,
		mNamePrefix.size() - 1);
	newName.append(mNamePrefix.at(number));
	if (Randomness::getSingleton()->nextUnifPosInt(0, 1)) {
		newName.append(
			mNameStems.at(
				Randomness::getSingleton()->nextUnifPosInt(0,
					mNameStems.size() - 1)));
	}
	//The name can not be fully empty, it must at least either have a prefix or a suffix.
	if (number != 0) {
		newName.append(
			mNameSuffix.at(
				Randomness::getSingleton()->nextUnifPosInt(0,
					mNameSuffix.size() - 1)));
	} else {
		newName.append(
			mNameSuffix.at(
				Randomness::getSingleton()->nextUnifPosInt(1,
					mNameSuffix.size() - 1)));
	}

	//Make the first letter capital...
	newName[0] = toupper(newName.at(0));
	return newName;
}
