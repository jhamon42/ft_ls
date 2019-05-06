/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:50:40 by jhamon            #+#    #+#             */
/*   Updated: 2019/05/06 16:34:11 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int ft_reverce(DIR * dir)
{
  struct dirent *dent;
  if ((dent=readdir(dir))!=NULL)
  {
    printf("%s\n",dent->d_name);
    ft_reverce(dir);
  }
  return 1;
}

int main(int argc, char *argv[]) {
  struct stat sb;
  struct passwd *pwd;
  // struct dirent *dent;
  const clock_t t = clock();
  DIR *dir;
  int cc;
  char buf[BUFSIZ];
  char buffer[50];

  if (argc != 2) {
    argv[1] = ".";
  }

  if (lstat(argv[1], &sb) == -1) {
    perror("stat");
    exit(EXIT_SUCCESS);
  }

  if ((pwd = getpwuid(sb.st_uid)) == NULL) {
    perror("passwd");
    exit(EXIT_SUCCESS);
  }


  strcpy(buffer, argv[1]);
  dir = opendir(buffer);
  if((cc = readlink("testFile/linkS_", buf, BUFSIZ)) == -1){
    perror("readlink");
    exit(EXIT_SUCCESS);
  }
  buf[cc] = '\0';

  printf("%s\n", buffer);
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
  printf("File Permissions:                  ");
  printf( (S_ISDIR(sb.st_mode)) ? "d" : "-");
  printf( (sb.st_mode & S_IRUSR) ? "r" : "-");
  printf( (sb.st_mode & S_IWUSR) ? "w" : "-");
  printf( (sb.st_mode & S_IXUSR) ? "x" : "-");
  printf( (sb.st_mode & S_IRGRP) ? "r" : "-");
  printf( (sb.st_mode & S_IWGRP) ? "w" : "-");
  printf( (sb.st_mode & S_IXGRP) ? "x" : "-");
  printf( (sb.st_mode & S_IROTH) ? "r" : "-");
  printf( (sb.st_mode & S_IWOTH) ? "w" : "-");
  printf( (sb.st_mode & S_IXOTH) ? "x" : "-");
  printf("\n");
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
  if(dir!=NULL)
  {
    ft_reverce(dir);
    // while((dent=readdir(dir))!=NULL)
    // printf("%s\n",dent->d_name);
    closedir(dir);
  }
  const clock_t t2 = clock();
  printf("time execute:                      %f ms\n",                (t2-t) * 1000.0 / CLOCKS_PER_SEC);
  exit(EXIT_SUCCESS);
}


#define SYS_ERR -1
