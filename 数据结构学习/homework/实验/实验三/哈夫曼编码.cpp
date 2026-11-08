// 2、题目要求：根据哈夫曼编码的原理，编写一个程序，在用户输入结点权值的基础上求赫夫曼编码，并能把给定的编码进行译码。
// （1）初始化：从键盘输入一字符串（或读入一文件），统计出现的字符和每个字符出现的频率，
//将字符出现的频率作为结点的权值，建立哈夫曼树。对各个字符进行哈夫曼编码，
//最后打印输出字符及每个字符对应的哈夫曼编码。 
// （2）编码：利用已建好的哈夫曼树对“输入串”进行哈夫曼编码，最后打印输入串对应的哈夫曼编码（写入文件）。 
// （3）译码：利用已建好的哈夫曼树对给定的一串代码进行译码，并打印输出得到的字符串。 
// 测试数据：对字符串{casbcatbsatbat}进行编码；对电文“1101000”译码。字符集D={   ？},出现频率为w={？} 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// int initHuffman(string s){
//     int cnt[128]={0};
//     for(int i=0;i<s.size();i++){
//         char c=s[i];//比如输入的第一个字符是a，就将a先拿出来
//         cnt[(unsigned int)c]++;//将a转化成97存到数组里面，读到一个就加1
//     }
//     //cout<<"字符\t出现频率"<<endl;
//     // for(int i=0;i<128;i++){
//     //     if(cnt[i]>0){
//     //         cout<<char(i)<<"\t"<<cnt[i]<<endl;
//     //     }
//     // }
// }
#define MAXSIZE 1000
typedef struct HuffNode {
    char ch;         // 存对应的字符
    int weight;      // 权值 = 字符出现频率
    struct HuffNode *lchild, *rchild;
    HuffNode(char c,int w){
        ch=c;
        weight=w;
        lchild=NULL;
        rchild=NULL;
    }
} HuffNode, *HuffTree;

void getcode(HuffTree T,string code){
    //值传递
    if(T==NULL){
        return ;
    }
    if(T->lchild==NULL&&T->rchild==NULL){
        cout<<T->ch<<":"<<code<<endl;
    }//如果左右孩子都为空，叶子节点，直接传入code
    getcode(T->lchild,code+"0");
    getcode(T->rchild,code+"1");
}
bool cmp(HuffTree a,HuffTree b){
    return a->weight<b->weight;
}
int main(){
    string s;
    cin>>s;
    int cnt[128]={0};
    for(int i=0;i<s.size();i++){
        char c=s[i];
        cnt[(int)c]++;
    }
    vector<HuffNode*>nodelist;
    for(int i=0;i<128;i++){
        if(cnt[i]>0){
            nodelist.push_back(new HuffNode((char)i,cnt[i]));
        }
    }
    while(nodelist.size()>1){
        sort(nodelist.begin(),nodelist.end(),cmp);
        HuffNode*n1=nodelist[0];
        HuffNode*n2=nodelist[1];
        HuffNode*parent=new HuffNode('#',n1->weight+n2->weight);
        parent->lchild=n1;
        parent->rchild=n2;
        nodelist.erase(nodelist.begin(),nodelist.begin()+2);
        nodelist.push_back(parent);
    }
    cout<<"哈夫曼编码:"<<endl;
    getcode(nodelist[0],"");
    return 0;
    
}