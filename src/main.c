/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:50:40 by jhamon            #+#    #+#             */
/*   Updated: 2019/04/15 12:48:57 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



int main(int argc, char *argv[]) {
  struct stat sb;
  struct passwd *pwd;
  const clock_t t = clock();

  printf("%lu\n", t);
     if (argc != 2) {
         fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
         exit(EXIT_FAILURE);
     }

     if (stat(argv[1], &sb) == -1) {
         perror("stat");
         exit(EXIT_SUCCESS);
     }

     if ((pwd = getpwuid(sb.st_uid)) == NULL) {
         perror("passwd");
         exit(EXIT_SUCCESS);
     }

     printf("Type de fichier :                ");
     switch (sb.st_mode & S_IFMT) {
     case S_IFBLK:  printf("périphérique de bloc\n");      break;
     case S_IFCHR:  printf("périphérique de caractère\n"); break;
     case S_IFDIR:  printf("répertoire\n");                break;
     case S_IFIFO:  printf("FIFO/tube\n");                 break;
     case S_IFLNK:  printf("lien symbolique\n");           break;
     case S_IFREG:  printf("fichier ordinaire\n");         break;
     case S_IFSOCK: printf("socket\n");                    break;
     default:       printf("inconnu ?\n");                 break;
     }
     printf("Numéro d'inœud :                   %ld\n",               (long) sb.st_ino);
     printf("Mode :                             %lo (octal)\n",       (unsigned long) sb.st_mode);
     printf("Nombre de liens :                  %ld\n",               (long) sb.st_nlink);
     printf("Propriétaires :                    UID=%ld   GID=%ld\n", (long) sb.st_uid, (long) sb.st_gid);
     printf("Taille de bloc d’E/S :             %ld octets\n",        (long) sb.st_blksize);
     printf("Taille du fichier :                %lld octets\n",       (long long) sb.st_size);
     printf("Blocs alloués :                    %lld\n",              (long long) sb.st_blocks);
     printf("Dernier changement d’état :        %s\n",                ctime(&sb.st_ctime));
     printf("Dernier accès au fichier :         %s\n",                ctime(&sb.st_atime));
     printf("Dernière modification du fichier:  %s\n",                ctime(&sb.st_mtime));
     printf("Nom d'utilisateur:                 %s\n",                pwd->pw_name);
     printf("Mot de passe                       %s\n",                pwd->pw_passwd);
     printf("ID de l'utilisateur                %ld\n",               (long) pwd->pw_uid);
     printf("Programme Shell de connexion       %s\n",                pwd->pw_shell);
     printf("ID du groupe de l'utilisateur      %ld\n",               (long) pwd->pw_gid);
     printf("Répertoire de connexion            %s\n",                pwd->pw_dir);
     printf("Nom réel de l'utilisateur          %s\n",                pwd->pw_gecos);
     for(int i=0; i<100; i++) {}
     const clock_t t2 = clock();
     printf("%f\n", (t2-t) * 1000.0 / CLOCKS_PER_SEC);
     printf("%lu\n", t2);
     exit(EXIT_SUCCESS);
}
