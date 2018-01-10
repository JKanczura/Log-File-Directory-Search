#include <dirent.h>
#include <stdio.h>

#define MAX_SIZE 100

int main(int argc,char* argv[]){
  char cwd[MAX_SIZE];
  struct dirent *d;
  DIR *targetDir;

  if(argv[1] == '\0'){
    printf("if 1a\n");
    if(getcwd(cwd, sizeof(cwd)) != NULL){
      targetDir = opendir(cwd);
      printf("if 2a\n");
    }
    else{
      printf("There was an error opening the directory.");
      return 1; }}
  else{
    targetDir = opendir(argv[1]);
    }


  if (targetDir == NULL){
    printf("Directory does not exist.\n");
    return 1; }


  chdir(targetDir);


  while(targetDir != NULL){
    if((d = readdir(targetDir)) != NULL){
      int size = strlen(d->d_name);
      if(size >= 4 &&
         d->d_name[size-4] == '.' &&
         d->d_name[size-3] == 'l' &&
         d->d_name[size-2] == 'o' &&
         d->d_name[size-1] == 'g'){
        printf("%s\n", d->d_name);
      }}
    else if(readdir(targetDir) == NULL){
      closedir(targetDir);
      break;}
    }

}

