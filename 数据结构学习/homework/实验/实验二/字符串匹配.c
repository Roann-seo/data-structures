// 注病毒感染检测 ，人的DNA和病毒DNA均表示成由一些字母组成的字符串序列。
// 然后检测某种病毒DNA序列是否在患者的DNA序列中出现过，如果出现过，则此人感染了该病毒，否则没有感染。
// 例如，假设病毒的DNA序列为baa，患者1的DNA序列为aaabbba，则感染，患者2的DNA序列为babbba，则未感染。
// （注意，人的DNA序列是线性的，而病毒的DNA序列是环状的)
// 输入格式:
// 输入第一行中给出1个整数i(1≤i≤11)，表示待检测的病毒DNA和患者DNA的对数。
//输入i行串序列，每行由两个字符串组成（字符串中不含不可见字符），两字符串之间用一个空格分隔，
//分别代表病毒的DNA序列和患者的DNA序列，病毒的DNA序列和患者的DNA序列长度不超过500。
// 输出格式:
// 依次逐行输出每对检测样本的结果，感染输出：YES，未感染输出：NO。
#include<stdio.h>
#include<string.h>
//判断a是否为b的子串
int issub(char*a,char*b){
    int la=strlen(a);
    int lb=strlen(b);
    for(int i=0;i<lb-la;i++){
        int flag=1;
        for(int j=0;j<la;j++){
            //j是偏移量
            if(a[j]!=b[i+j]){
                flag=0;
                break;
            }
        }
        if(flag){
            return 1;
        }
    }
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char vitus[505],patient[505];
        scanf("%s %s",vitus,patient);
        int lv=strlen(vitus);
        int lp=strlen(patient);
        if(lv>lp){
            printf("NO");
            continue;
        }
        char vv[1010];
        strcpy(vv,vitus);
        strcat(vv,vitus);
        int flag=0;
        //循环病毒
        for(int i=0;i<lv;i++){
            char rot[505];
            strncpy(rot,vv+i,lv);
            rot[lv]='\0';
            if(issub(rot,patient)){
                flag=1;
                break;;
            }
        }
        if(flag==1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}