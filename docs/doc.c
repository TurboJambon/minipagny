
//Fonctions autorisees
//____________________

char	*getcwd(char *buf, size_t size)
//La fonction getcwd() copie le chemin d'accès absolu du répertoire de travail courant dans la chaîne pointée par buf, qui est de longueur size.
//Renvoie NULL en cas d'erreur, buf en cas de reussite.

int 	chdir(const char *path); 
//Remplace le répertoire de travail courant du processus appelant par celui indiqué dans le chemin path.
//Renvoie 0 en cas de reussite, -1 en cas d'echec.

int 	fstat(int fd, struct stat *buf); 
//Pareil que stat, mais prend fd en argument a la place de path.