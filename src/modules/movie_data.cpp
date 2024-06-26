#include "movie_data.h"

namespace faker::movie::data {
const std::array<std::string_view, 299> actors = { "Marlon Brando", "Charles Chaplin",
    "Laurence Olivier",
    "Robert De Niro"
    "James Stewart",
    "Jack Nicholson", "Al Pacino", "Paul Newman", "Humphrey Bogart", "Toshiro Mifune", "Cary Grant",
    "Buster Keaton", "Dustin Hoffman", "Marcello Mastroianni", "Daniel Day-Lewis", "Henry Fonda",
    "Alec Guinness", "Jean Gabin", "Jack Lemmon", "John Wayne", "Tom Hanks", "Gregory Peck",
    "Sidney Poitier", "Gary Cooper", "James Cagney", "Gérard Depardieu", "Spencer Tracy",
    "Peter O'Toole", "Gene Hackman", "Denzel Washington", "Michael Caine", "Clark Gable",
    "Richard Burton", "Max von Sydow", "Burt Lancaster", "Clint Eastwood", "Jean-Paul Belmondo",
    "William Holden", "Robert Mitchum", "Peter Sellers", "Kirk Douglas", "Morgan Freeman",
    "Leonardo DiCaprio", "Vittorio Gassman", "Orson Welles", "Harold Lloyd", "Sean Connery",
    "Robert Duvall", "Anthony Quinn", "Rudolph Valentino", "George C. Scott", "Robert Redford",
    "Montgomery Clift", "Anthony Hopkins", "James Dean", "Alain Delon", "Michel Piccoli",
    "Klaus Kinski", "Harrison Ford", "Gene Kelly", "Peter Lorre", "Fred Astaire",
    "Edward G. Robinson", "Charles Laughton", "Takashi Shimura", "Sean Penn",
    "Philip Seymour Hoffman", "Gary Oldman", "Max Linder", "Groucho Marx / The Marx Brothers",
    "Ronald Colman", "Douglas Fairbanks", "Tom Cruise", "Tatsuya Nakadai", "Johnny Depp",
    "Ben Kingsley", "Fredric March", "Dennis Hopper", "James Mason", "Louis de Funès",
    "Robin Williams", "Michel Simon", "Woody Allen", "Philippe Noiret", "Bill Murray", "Totò",
    "Jeff Bridges", "Amitabh Bachchan", "John Barrymore", "Chishu Ryu", "Lon Chaney",
    "Jean-Louis Trintignant", "Laurel and Hardy", "Jean-Pierre Léaud", "Errol Flynn",
    "Albert Finney", "Emil Jannings", "John Hurt", "Russell Crowe", "Walter Matthau", "Uttam Kumar",
    "George Clooney", "Rod Steiger", "Warren Beatty", "Ralph Fiennes", "Tony Leung Chiu Wai",
    "Richard Harris", "Raj Kapoor", "Yves Montand", "Yul Brynner", "Charlton Heston",
    "Steve McQueen", "Mickey Rooney", "Boris Karloff", "Dirk Bogarde", "John Gielgud",
    "Vincent Price", "Chow Yun-fat", "Alberto Sordi", "Conrad Veidt", "Christopher Walken",
    "Donald Sutherland", "Kevin Spacey", "Samuel L. Jackson", "Michael Douglas", "Dilip Kumar",
    "Paul Muni", "Lee Marvin", "Jean Marais", "Jerry Lewis", "Rock Hudson", "Ian McKellen",
    "Naseeruddin Shah", "Mack Sennett", "Geoffrey Rush", "Omar Sharif", "Roscoe 'Fatty' Arbuckle",
    "Peter Finch", "Lionel Barrymore", "Rajesh Khanna", "Sessue Hayakawa", "King Baggot",
    "Jacques Tati", "Jeremy Irons", "Jon Voight", "Brad Pitt", "Kenneth Branagh",
    "Richard Attenborough", "Gérard Philipe", "Erland Josephson", "Jim Carrey", "Farid Shawqi",
    "Ernest Borgnine", "Matt Damon", "Shah Rukh Khan", "Charles Boyer", "Javier Bardem",
    "Bruce Lee", "William Hurt", "Liam Neeson", "Fernandel", "Nino Manfredi", "David Niven",
    "Ralph Richardson", "Erich von Stroheim", "Daniel Auteuil", "Richard Dreyfuss",
    "William S. Hart", "Adel Imam", "Innokenty Smoktunovsky", "Fernando Rey", "Maximilian Schell",
    "Jackie Chan", "Edward Norton", "Tony Curtis", "Walter Brennan", "Dev Anand",
    "Gunnar Björnstrand", "W.C. Fields", "Ed Harris", "Tommy Lee Jones", "Bourvil",
    "Christian Bale", "Aamir Khan", "Christopher Lee", "Will Smith", "Claude Rains", "Gene Wilder",
    "José Ferrer", "Fernando Fernán Gómez", "Nikolay Cherkasov", "Ryan Gosling", "Nicolas Cage",
    "Michel Serrault", "Ugo Tognazzi", "Choi Min-sik", "Arthur Kennedy", "Joseph Cotten",
    "Willem Dafoe", "Thomas Mitchell", "Cantinflas", "Karl Malden", "Heath Ledger", "Bruno Ganz",
    "John Gilbert", "James Coburn", "Stellan Skarsgård", "Gian Maria Volonté", "Eli Wallach",
    "Ahmed Zaki", "Jean-Claude Brialy", "Melvyn Douglas", "Bob Hope", "Walter Huston",
    "Abbott and Costello", "Nanni Moretti", "Paul Robeson", "Wallace Beery", "Tom Courtenay",
    "George Sanders", "Richard Gere", "Joel McCrea", "Viggo Mortensen", "Ewan McGregor",
    "Bela Lugosi", "Harvey Keitel", "John Malkovich", "The Three Stooges", "Paul Scofield",
    "Robert Shaw", "Gaston Modot", "Benicio del Toro", "John Carradine", "Harry Dean Stanton",
    "Raimu", "Paul Winfield", "Mel Gibson", "Rex Harrison", "Bing Crosby", "James Earl Jones",
    "Robert Downey Jr.", "Steve Buscemi", "Denholm Elliott", "Roberto Benigni", "Dana Andrews",
    "Michael Chekhov", "Jason Robards", "Leslie Cheung", "Martin Sheen", "Joe Pesci",
    "Rudolf Klein-Rogge", "Robert Ryan", "William Powell", "Joaquin Phoenix", "Peter Cushing",
    "Takeshi Kitano", "Jake Gyllenhaal", "Robert Donat", "Matthew McConaughey", "John Travolta",
    "James Woods", "Donald Crisp", "Pedro Infante", "Lee J. Cobb", "Alan Rickman", "Alastair Sim",
    "Richard Widmark", "Victor Mature", "Victor McLaglen", "Michael Redgrave",
    "Armin Mueller-Stahl", "Anthony Perkins", "Walter Pidgeon", "Giancarlo Giannini", "Bob Hoskins",
    "Glenn Ford", "Gael García Bernal", "James Caan", "Martin Balsam", "Alan Arkin",
    "Brendan Gleeson", "Andy Serkis", "Leslie Howard", "Woody Harrelson", "Steve Martin",
    "Martin Landau", "Edward Everett Horton", "Arnold Schwarzenegger", "Tim Robbins",
    "Sterling Hayden", "Don Cheadle", "Chris Cooper", "Frank Sinatra", "Roy Scheider",
    "Vincent Cassel", "Rutger Hauer", "Gert Fröbe", "Michael Fassbender", "John Cleese",
    "Jean Hersholt" };

const std::array<std::string_view, 300> actresses = { "Katharine Hepburn", "Meryl Streep",
    "Bette Davis", "Ingrid Bergman", "Audrey Hepburn", "Greta Garbo", "Lillian Gish",
    "Elizabeth Taylor", "Catherine Deneuve", "Barbara Stanwyck", "Jane Fonda", "Diane Keaton",
    "Marlene Dietrich", "Shirley MacLaine", "Jeanne Moreau", "Joan Crawford", "Sophia Loren",
    "Judy Garland", "Liv Ullmann", "Mary Pickford", "Olivia de Havilland", "Faye Dunaway",
    "Grace Kelly", "Marilyn Monroe", "Norma Shearer", "Julie Christie", "Deborah Kerr",
    "Claudia Cardinale", "Kate Winslet", "Greer Garson", "Judi Dench", "Isabelle Huppert",
    "Juliette Binoche", "Cate Blanchett", "Julianne Moore", "Sissy Spacek", "Susan Sarandon",
    "Ginger Rogers", "Jessica Lange", "Lauren Bacall", "Jane Wyman", "Monica Vitti",
    "Julia Roberts", "Maggie Smith", "Meena Kumari", "Emma Thompson", "Anna Magnani",
    "Claudette Colbert", "Jodie Foster", "Ava Gardner", "Vivien Leigh", "Gloria Swanson",
    "Simone Signoret", "Frances McDormand", "Glenn Close", "Anna Karina", "Vanessa Redgrave",
    "Faten Hamama", "Rosalind Russell", "Setsuko Hara", "Nicole Kidman", "Helen Mirren",
    "Alida Valli", "Michèle Morgan", "Julie Andrews", "Anne Bancroft", "Brigitte Bardot",
    "Natalie Wood", "Louise Brooks", "Ellen Burstyn", "Rita Hayworth", "Glenda Jackson",
    "Jennifer Jones", "Joan Fontaine", "Susan Hayward", "Sally Field", "Michelle Pfeiffer",
    "Shelley Winters", "Geraldine Page", "Kathy Bates", "Annette Bening", "Sridevi",
    "Isabelle Adjani", "Carole Lombard", "Gena Rowlands", "Arletty", "Doris Day", "Bibi Andersson",
    "Stefania Sandrelli", "Sigourney Weaver", "Madhuri Dixit", "Pola Negri", "Jean Arthur",
    "Danielle Darrieux", "Joanne Woodward", "Giulietta Masina", "Asta Nielsen", "Madhubala",
    "Shadia", "Florence Lawrence", "Clara Bow", "Annie Girardot", "Gong Li", "Jean Harlow",
    "Miriam Hopkins", "Helena Bonham Carter", "Machiko Kyo", "Jean Simmons", "Kajol",
    "Angela Lansbury", "Anjelica Huston", "Holly Hunter", "Penélope Cruz", "Tilda Swinton",
    "Kinuyo Tanaka", "Amy Adams", "Mia Farrow", "Irene Dunne", "Harriet Andersson", "Anouk Aimée",
    "Dianne Wiest", "Delphine Seyrig", "Nutan", "Maria Félix", "Dorothy Gish", "Valeria Golino",
    "Hema Malini", "Mariangela Melato", "Romy Schneider", "Fanny Ardant", "Joan Allen",
    "Laura Linney", "Myrna Loy", "Maggie Cheung", "Natalie Portman", "Shirley Temple",
    "Gene Tierney", "Marion Cotillard", "Aishwarya Rai", "Maribel Verdú", "Lana Turner",
    "Fatemeh Motamed-Arya", "Katy Jurado", "Theda Bara", "Jaya Bachchan", "Stéphane Audran",
    "Mae West", "Vyjayanthimala", "Dorothy Dandridge", "Francesca Bertini", "Renée Zellweger",
    "Barbra Streisand", "Liza Minnelli", "Gina Lollobrigida", "Ruan Lingyu", "Nargis", "Zhang Ziyi",
    "Paulette Goddard", "Sandrine Bonnaire", "Margherita Buy", "Vera Kholodnaya",
    "Emmanuelle Béart", "Mabel Normand", "Nathalie Baye", "Charlize Theron", "Ingrid Thulin",
    "Asha Parekh", "Norma Talmadge", "Thelma Ritter", "Simone Simon", "Dolores del Río",
    "Michelle Williams", "Faina Ranevskaya", "Mary Queeny", "Henny Porten", "Hind Rostom",
    "Miou-Miou", "Winona Ryder", "Kristin Scott Thomas", "Hanna Schygulla", "Angelina Jolie",
    "Jacqueline Bisset", "Victoria Abril", "Judy Davis", "Hamideh Kheiradabi", "Kyoko Kagawa",
    "Shohreh Aghdashloo", "Joan Blondell", "Mariam Fakhr Eddine", "Mary Astor", "Barbara Hershey",
    "Soad Hosny", "Ethel Barrymore", "Jennifer Lawrence", "Goldie Hawn", "Vilma Bánky",
    "Eleanor Parker", "Nimmi", "Maureen O'Hara", "Naomi Watts", "Silvana Mangano",
    "Keira Knightley", "Lupe Vélez", "Suchitra Sen", "Halle Berry", "Elsa Lanchester",
    "Veronica Lake", "Emmanuelle Riva", "Yousra", "Kathleen Turner", "Luise Rainer",
    "Anna May Wong", "Teresa Wright", "Claire Trevor", "Jennifer Connelly", "Viola Davis",
    "Dolores Costello", "Donna Reed", "Blanche Sweet", "Debbie Reynolds", "Janet Leigh",
    "Virna Lisi", "Leila Hatami", "Sandra Bullock", "Laura Dern", "Geena Davis", "Salma Hayek",
    "Sharon Stone", "Colleen Moore", "Clara Kimball Young", "Agnes Moorehead", "Reese Witherspoon",
    "Charlotte Rampling", "Lyudmila Gurchenko", "Anne Hathaway", "Angela Bassett", "Debra Winger",
    "Mercedes McCambridge", "Emily Watson", "Uma Thurman", "Bette Midler", "Jessica Tandy",
    "Audrey Tautou", "Carmen Maura", "Monica Bellucci", "Sylvia Chang", "Eva Marie Saint",
    "Hilary Swank", "Marie Dressler", "Charlotte Gainsbourg", "Golshifteh Farahani", "Janet Gaynor",
    "Catherine Frot", "Marisa Tomei", "Gisèle Casadesus", "Jessica Chastain", "Gloria Grahame",
    "Anne Baxter", "Gwyneth Paltrow", "Lee Remick", "Lyubov Orlova", "Patricia Neal", "Jean Seberg",
    "Leslie Caron", "Jane Alexander", "Ann-Margret", "Hedy Lamarr", "Joan Bennett", "Cameron Diaz",
    "Maria Ouspenskaya", "Lilli Palmer", "Jayne Mansfield", "María Antonieta Pons", "Diane Ladd",
    "Beulah Bondi", "Judith Anderson", "Brenda Blethyn", "Anne Revere", "Maria Schell",
    "Irène Jacob", "Betty Grable", "Mieko Harada", "Wendy Hiller", "Maria Montez",
    "Whoopi Goldberg", "Edith Evans", "Emma Stone", "Maureen Stapleton", "Octavia Spencer",
    "Jennifer Jason Leigh", "Ruth Gordon", "Marcia Gay Harden", "Piper Laurie", "Sara García",
    "Rooney Mara", "Catherine Zeta-Jones", "Raquel Welch", "Carmen Miranda", "Michelle Yeoh",
    "Scarlett Johansson" };

const std::array<std::string_view, 300> directors = { "Alfred Hitchcock", "John Ford",
    "Charles Chaplin", "Akira Kurosawa", "D. W. Griffith", "Jean Renoir", "Sergei M. Eisenstein",
    "Orson Welles", "Stanley Kubrick", "Georges Méliès", "Luis Buñuel", "Fritz Lang",
    "Jean-Luc Godard", "Federico Fellini", "F. W. Murnau", "Ingmar Bergman", "Carl Theodor Dreyer",
    "Howard Hawks", "Yasujirō Ozu", "Robert Bresson", "François Truffaut", "Martin Scorsese",
    "Cecil B. DeMille", "Satyajit Ray", "Andrei Tarkovsky", "Ernst Lubitsch", "Steven Spielberg",
    "Michelangelo Antonioni", "John Cassavetes", "Billy Wilder", "Buster Keaton",
    "Erich von Stroheim", "Roberto Rossellini", "Kenji Mizoguchi", "Woody Allen", "Robert Altman",
    "David Lean", "Abbas Kiarostami", "Dziga Vertov", "Frank Capra", "Roman Polański",
    "Luchino Visconti", "David Lynch", "Jean Vigo", "Stanley Donen (& Gene Kelly)",
    "Hayao Miyazaki", "Werner Herzog", "Michael Powell (& Emeric Pressburger)", "Quentin Tarantino",
    "Joel & Ethan Coen", "Francis Ford Coppola", "Robert J. Flaherty", "James Cameron", "Spike Lee",
    "Raoul Walsh", "Bernardo Bertolucci", "Sergio Leone", "Ridley Scott", "Vittorio De Sica",
    "Douglas Sirk", "Victor Sjöström", "Alexander Dovzhenko", "Paul Thomas Anderson", "Mario Bava",
    "Nicholas Ray", "Sam Peckinpah", "John Carpenter", "Wong Kar-Wai", "Josef von Sternberg",
    "Rainer Werner Fassbinder", "Jean-Pierre Melville", "Max Ophüls", "Wes Anderson",
    "Sidney Lumet", "George A. Romero", "Maurice Tourneur", "Busby Berkeley", "David Cronenberg",
    "Jean Cocteau", "John Huston", "Samuel Fuller", "Krzysztof Kieślowski", "Louis Feuillade",
    "Terrence Malick", "Edwin S. Porter", "Chantal Akerman", "Alain Resnais", "Michael Curtiz",
    "Claude Chabrol", "Maya Deren", "Chuck Jones", "Wim Wenders", "Pier Paolo Pasolini",
    "Stan Brakhage", "Lars von Trier", "Jacques Tati", "Richard Linklater", "Preston Sturges",
    "Jim Jarmusch", "Christopher Nolan", "Abel Gance", "Pedro Almodóvar", "Roger Corman",
    "Lois Weber", "Louis Malle", "George Cukor", "William Wyler", "Hou Hsiao-Hsien",
    "Vsevolod Pudovkin", "Elia Kazan", "King Vidor", "Dario Argento", "Cecil Hepworth",
    "Winsor McCay", "Andrzej Wajda", "Zhang Yimou", "Louis & Auguste Lumière", "James Whale",
    "Clint Eastwood", "Todd Haynes", "Chris Marker", "Agnès Varda", "Vincente Minnelli",
    "Tod Browning", "William K.L. Dickson", "Robert Wise", "Anthony Mann", "David Fincher",
    "Michael Haneke", "J. Stuart Blackton", "Kenneth Anger", "Mike Leigh", "Claire Denis",
    "Frank Borzage", "G. W. Pabst", "Miloš Forman", "Brian De Palma", "Fred Niblo", "Mike Nichols",
    "Arthur Penn", "John Frankenheimer", "René Clair", "Gus Van Sant", "George Miller",
    "Danny Boyle", "Marcel Carné", "Don Siegel", "Leni Riefenstahl", "Sidney Olcott",
    "Walt Disney/Ub Iwerks", "Charles Burnett", "Jack Arnold", "Jacques Rivette", "John Woo",
    "Tim Burton", "Chen Kaige", "Otto Preminger", "Ken Loach", "Joseph L. Mankiewicz",
    "John Lasseter", "Gordon Parks", "Tex Avery", "Béla Tarr", "Terry Gilliam", "Ang Lee",
    "Steven Soderbergh", "Fred Zinnemann", "Mack Sennett", "Theodoros Angelopoulos", "Éric Rohmer",
    "Mauritz Stiller", "Nagisa Ōshima", "Jean Rouch", "Jia Zhangke", "John Hughes", "Peter Weir",
    "William Friedkin", "Robert Zemeckis", "Alfonso Cuarón", "Carol Reed", "Jacques Demy",
    "Leo McCarey", "Peter Jackson", "D. A. Pennebaker", "Sam Raimi", "George Lucas",
    "George Stevens", "Ousmane Sembène", "Mel Brooks", "Rouben Mamoulian", "Kathryn Bigelow",
    "Robert Aldrich", "Errol Morris", "Michael Mann", "Ishirō Honda", "Boris Barnet",
    "Paul Verhoeven", "Nicolas Roeg", "Henri-Georges Clouzot", "John Waters", "William A. Wellman",
    "Lindsay Anderson", "Oliver Stone", "Andy Warhol/Paul Morrissey", "Richard Lester",
    "Alejandro Jodorowsky", "William Castle", "Edward Yang", "Ida Lupino", "Jacques Becker",
    "Jane Campion", "Stephen Frears", "Alejandro González Iñárritu", "Mario Monicelli",
    "Sergei Parajanov", "Rob Reiner", "Paul Greengrass", "Takeshi Kitano", "Alice Guy-Blaché",
    "Henry King", "Glauber Rocha", "Ken Russell", "Apichatpong Weerasethakul", "Budd Boetticher",
    "Albert & David Maysles", "Jules Dassin", "John Landis", "John Boorman", "Aki Kaurismäki",
    "Kevin Smith", "Mervyn LeRoy", "Oscar Micheaux", "Hal Ashby", "John Sayles",
    "Jean-Pierre & Luc Dardenne", "Robert Siodmak", "Richard Donner", "Anthony Asquith",
    "Mikio Naruse", "Lev Kuleshov", "Nuri Bilge Ceylan", "Peter Bogdanovich", "Ralph Bakshi",
    "Tsai Ming-Liang", "Joseph Losey", "John Schlesinger", "Peter Watkins", "Darren Aronofsky",
    "Wes Craven", "Allan Dwan", "Alexander Sokurov", "Georges Franju", "Russ Meyer", "Walter Hill",
    "Joris Ivens", "Jan Švankmajer", "Alexander Mackendrick", "Frederick Wiseman", "Yevgeni Bauer",
    "Robert Rodríguez", "Pedro Costa", "Alexander Payne", "Mohsen Makhmalbaf", "Julien Duvivier",
    "Manoel de Oliveira", "Yuriy Norshteyn", "Dorothy Arzner", "Blake Edwards", "Olivier Assayas",
    "Sydney Pollack", "Raj Kapoor", "Luis García Berlanga", "Edgar G. Ulmer", "Emir Kusturica",
    "Guillermo del Toro", "Costa-Gavras", "Guy Maddin", "Morris Engel", "Jerry Lewis",
    "Alan J. Pakula", "Sadao Yamanaka", "Herschell Gordon Lewis", "Dave Fleischer", "James Ivory",
    "Jonathan Demme", "Terence Davies", "Kon Ichikawa", "Bong Joon-Ho", "Peter Greenaway",
    "Victor Fleming", "David O. Russell", "Bob Clampett", "Clarence Brown", "Jacques Tourneur",
    "Claude Lanzmann", "Michael Cimino", "Sofia Coppola", "Lasse Hallström", "Miklós Jancsó",
    "Henry Hathaway" };

const std::array<std::string_view, 9> genres = {
    "Action",
    "Comedy",
    "Drama",
    "Fantasy",
    "Horror",
    "Mystery",
    "Romance",
    "Thriller",
    "Western",
};

const std::array<std::string_view, 250> movies = { "The Shawshank Redemption", "The Godfather",
    "The Godfather: Part II", "Il buono, il brutto, il cattivo.", "Pulp Fiction", "Inception",
    "Schindler's List", "12 Angry Men", "One Flew Over the Cuckoo's Nest", "The Dark Knight",
    "Star Wars: Episode V - The Empire Strikes Back",
    "The Lord of the Rings: The Return of the King", "Shichinin no samurai", "Star Wars",
    "Goodfellas", "Casablanca", "Fight Club", "Cidade de Deus",
    "The Lord of the Rings: The Fellowship of the Ring", "Rear Window", "C'era una volta il West",
    "Raiders of the Lost Ark", "Toy Story 3", "Psycho", "The Usual Suspects", "The Matrix",
    "The Silence of the Lambs", "Se7en", "Memento", "It's a Wonderful Life",
    "The Lord of the Rings: The Two Towers", "Sunset Blvd.",
    "Dr. Strangelove or: How I Learned to Stop Worrying and Love the Bomb", "Forrest Gump", "Léon",
    "Citizen Kane", "Apocalypse Now", "North by Northwest", "American Beauty", "American History X",
    "Taxi Driver", "Terminator 2: Judgment Day", "Saving Private Ryan", "Vertigo",
    "Le fabuleux destin d'Amélie Poulain", "Alien", "WALL·E", "Lawrence of Arabia", "The Shining",
    "Sen to Chihiro no kamikakushi", "Paths of Glory", "A Clockwork Orange", "Double Indemnity",
    "To Kill a Mockingbird", "The Pianist", "Das Leben der Anderen", "The Departed", "M",
    "City Lights", "Aliens", "Eternal Sunshine of the Spotless Mind", "Requiem for a Dream",
    "Das Boot", "The Third Man", "L.A. Confidential", "Reservoir Dogs", "Chinatown",
    "The Treasure of the Sierra Madre", "Modern Times", "Monty Python and the Holy Grail",
    "La vita è bella", "Back to the Future", "The Prestige", "El laberinto del fauno",
    "Raging Bull", "Nuovo Cinema Paradiso", "Singin' in the Rain", "Some Like It Hot",
    "The Bridge on the River Kwai", "Rashômon", "All About Eve", "Amadeus",
    "Once Upon a Time in America", "The Green Mile", "Full Metal Jacket", "Inglourious Basterds",
    "2001: A Space Odyssey", "The Great Dictator", "Braveheart", "Ladri di biciclette",
    "The Apartment", "Up", "Der Untergang", "Gran Torino", "Metropolis", "The Sting", "Gladiator",
    "The Maltese Falcon", "Unforgiven", "Sin City", "The Elephant Man",
    "Mr. Smith Goes to Washington", "Oldeuboi", "On the Waterfront",
    "Indiana Jones and the Last Crusade", "Star Wars: Episode VI - Return of the Jedi", "Rebecca",
    "The Great Escape", "Die Hard", "Batman Begins", "Mononoke-hime", "Jaws", "Hotel Rwanda",
    "Slumdog Millionaire", "Det sjunde inseglet", "Blade Runner", "Fargo", "No Country for Old Men",
    "Heat", "The General", "The Wizard of Oz", "Touch of Evil", "Per qualche dollaro in più", "Ran",
    "Yôjinbô", "District 9", "The Sixth Sense", "Snatch.", "Donnie Darko", "Annie Hall",
    "Witness for the Prosecution", "Smultronstället", "The Deer Hunter", "Avatar",
    "The Social Network", "Cool Hand Luke", "Strangers on a Train", "High Noon", "The Big Lebowski",
    "Hotaru no haka", "Kill Bill: Vol. 1", "It Happened One Night", "Platoon", "The Lion King",
    "Into the Wild", "There Will Be Blood", "Notorious", "Million Dollar Baby", "Toy Story",
    "Butch Cassidy and the Sundance Kid", "Gone with the Wind", "Sunrise: A Song of Two Humans",
    "The Wrestler", "The Manchurian Candidate", "Trainspotting", "Ben-Hur", "Scarface",
    "The Grapes of Wrath", "The Graduate", "The Big Sleep", "Groundhog Day", "Life of Brian",
    "The Gold Rush", "The Bourne Ultimatum", "Amores perros", "Finding Nemo", "The Terminator",
    "Stand by Me", "How to Train Your Dragon", "The Best Years of Our Lives",
    "Lock, Stock and Two Smoking Barrels", "The Thing", "The Kid", "V for Vendetta", "Casino",
    "Twelve Monkeys", "Dog Day Afternoon", "Ratatouille", "El secreto de sus ojos", "Gandhi",
    "Star Trek", "Ikiru", "Le salaire de la peur", "Les diaboliques", "8½", "The Princess Bride",
    "The Night of the Hunter", "Judgment at Nuremberg", "The Incredibles", "Tonari no Totoro",
    "The Hustler", "Good Will Hunting", "The Killing", "In Bruges", "The Wild Bunch", "Network",
    "Le scaphandre et le papillon", "A Streetcar Named Desire", "Les quatre cents coups",
    "La strada", "The Exorcist", "Children of Men", "Stalag 17", "Persona",
    "Who's Afraid of Virginia Woolf?", "Ed Wood", "Dial M for Murder", "La battaglia di Algeri",
    "Låt den rätte komma in", "All Quiet on the Western Front", "Big Fish", "Magnolia", "Rocky",
    "La passion de Jeanne d'Arc", "Kind Hearts and Coronets", "Fanny och Alexander", "Mystic River",
    "Manhattan", "Barry Lyndon", "Kill Bill: Vol. 2", "Mary and Max", "Patton", "Rosemary's Baby",
    "Duck Soup", "Festen", "Kick-Ass", "Fa yeung nin wa", "Letters from Iwo Jima", "Roman Holiday",
    "Pirates of the Caribbean: The Curse of the Black Pearl", "Mou gaan dou", "The Truman Show",
    "Crash", "Hauru no ugoku shiro", "His Girl Friday", "Arsenic and Old Lace", "Harvey",
    "Le notti di Cabiria", "Trois couleurs: Rouge", "The Philadelphia Story", "A Christmas Story",
    "Sleuth", "King Kong", "Bom yeoreum gaeul gyeoul geurigo bom", "Rope", "Monsters, Inc.",
    "Tenkû no shiro Rapyuta", "Yeopgijeogin geunyeo", "Mulholland Dr.",
    "The Man Who Shot Liberty Valance" };

const std::array<std::string_view, 122> tv_shows = { "Planet Earth II", "Breaking Bad",
    "Planet Earth", "Band of Brothers", "Chernobyl", "The Wire", "Blue Planet II",
    "Avatar: The Last Airbender", "Cosmos: A Spacetime Odyssey", "The Sopranos", "Our Planet",
    "Cosmos", "Game of Thrones", "Rick and Morty", "The World at War",
    "Fullmetal Alchemist: Brotherhood", "The Last Dance", "Life", "Sherlock", "The Twilight Zone",
    "The Vietnam War", "Batman: The Animated Series", "Arcane", "The Blue Planet",
    "Attack on Titan", "The Office", "Firefly", "Human Planet", "Frozen Planet", "Death Note",
    "Only Fools and Horses", "True Detective", "The Civil War", "Hunter x Hunter",
    "The Beatles: Get Back", "Seinfeld", "Persona", "Fargo", "Dekalog", "Clarkson's Farm",
    "Cowboy Bebop", "Better Call Saul", "Nathan for You", "Gravity Falls", "Friends",
    "When They See Us", "Last Week Tonight with John Oliver", "Africa", "TVF Pitchers",
    "Apocalypse: The Second World War", "Monty Python's Flying Circus",
    "It's Always Sunny in Philadelphia", "Taskmaster", "Das Boot", "Curb Your Enthusiasm",
    "Fawlty Towers", "Pride and Prejudice", "The West Wing", "Freaks and Geeks", "Leyla and Mecnun",
    "Blackadder Goes Forth", "Twin Peaks", "Black Mirror", "Narcos", "BoJack Horseman",
    "Chappelle's Show", "Succession", "Dragon Ball", "I, Claudius", "South Park", "Rome",
    "Peaky Blinders", "One Piece", "Ted Lasso", "Oz", "Six Feet Under", "Over the Garden Wall",
    "Kota Factory", "Dark", "The Mandalorian", "As If", "Arrested Development", "Steins;Gate",
    "One Punch Man", "The Boys", "The Simpsons", "House M.D.", "Stranger Things", "The Rehearsal",
    "The Shield", "Fleabag", "Downton Abbey", "Invincible", "Mad Men", "Vinland Saga", "Gullak",
    "House of Cards", "The Crown", "Peep Show", "The Grand Tour", "The Thick of It", "Deadwood",
    "Dexter", "The X-Files", "Parks and Recreation", "This Is Us", "The Bridge", "Heartstopper",
    "Gomorrah", "Mindhunter", "Dopesick", "Boardwalk Empire", "Battlestar Galactica", "Westworld",
    "The IT Crowd", "Skam", "Sons of Anarchy", "Spartacus: Gods of the Arena", "Silicon Valley",
    "Twin Peaks", "Hannibal", "Community" };
}
