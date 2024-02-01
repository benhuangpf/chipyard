// #include <stdio.h>

// int main(void) {
//     FILE *in, *out;
//     in = fopen("/home/ben/chipyard/tests/in.txt","r+");
//     int t;
//     t = open("/home/ben/chipyard/tests/in.txt", 0, 0);
//     out = fopen("out.txt","w+");
//     int m;
//     fscanf(in, "%d", &m);
//     fprintf(out, "asdf");
//     printf("%d\n", t);
//   printf("Hello world from core 0\n");
//   return 0;
// }


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
 
const char *pathName = "out.txt"; 
 
int main(void) 
{ 
    int in, out, flag; 
    char buffer[1024];
    
    in = open("/home/ben/chipyard/tests/in.txt", O_RDONLY,S_IRUSR);
    printf("%d\n", in);
    // if (-1 == in) // 打开文件失败,则异常返回
    // {    
    //     return -1; 
    // }   
 
    out = open(pathName, O_WRONLY|O_CREAT);
    printf("%d\n", out);
    // if (-1 == out) // 创建文件失败,则异常返回
    // {   
    //     return -1; 
    // }   
    
    while ((flag = read(in, buffer, 1024)) > 0)
    {   
        write(out, buffer, flag);
    }   
    close(in);
    close(out);
    
    return 0;
} 