/* Modify the fsize program to print the other information contained in the inode entry. */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <pwd.h>


#define MAX_PATH 1024

#ifndef DIRSIZ
#define DIRSIZ 14
#endif

void dirwalk( char *dir,void (*fcn)(char *))    //this function walks throught the files in the directory given
{ 
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;

	if((dfd = opendir(dir))==NULL)
	{
		puts("Error: Cannot open Directory");
		return;
	}
	puts(dir);   //You print the directory name
	
	// Get each dir entry
	while((dp=readdir(dfd)) != NULL)  //dp is a pointer which reads the files in the directory
	{
		if(strcmp(dp->d_name,".") == 0 || strcmp(dp->d_name,"..") ==0 )   //. or .. means argc == 1, hence all the files in the current directory is to be accessed
			continue;
		if(strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))   //The length of the path must not exceed the given limit, +2 is for the /
			puts("Error: Name too long!");
		else
		{
			sprintf(name,"%s/%s",dir,dp->d_name); // we print the directory name and the associated filenamw
			(*fcn)(name);    //function call for fsize
		}
	}
	closedir(dfd);  //we close the directory
}

void fsize(char *name)
{
	struct stat stbuf;   

	if(stat(name,&stbuf) == -1)  //stbuf is a structur which stores the information 
	{
		puts("Error: Cannot get file stats!");
		return;
	}
	
	if((stbuf.st_mode & S_IFMT) == S_IFDIR)  //we check if it is a directory using built-in flags
	{
		dirwalk(name,fsize);
	}
	struct passwd *pwd = getpwuid(stbuf.st_uid);    //these are built-in functions to access the files
	
	//print file name,size and owner
	printf("%d %s Owner: %s\n",(int)stbuf.st_size, name,pwd->pw_name);
}




int main(int argc,char *argv[]){

	if(argc==1)   //no arguments are given
		fsize(".");
	else 
		while(--argc>0)
			fsize(*++argv);
	return 0;
}

