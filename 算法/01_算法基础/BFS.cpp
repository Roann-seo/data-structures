// Bob 在学习了 DFS 后，自己又发明了一种新的搜(luan)索(gao)方法，叫做 BFS（Bob First Search）。
// 这种搜索被定义为：在一个字符串中，从前向后查找子串 "Bob" 第一次出现的位置（不区分大小写）。
#include <iostream>
#include<string>
using namespace std;
char tolow(char c){
    if(c>='A'&&c<='Z'){
        return c-'A'+'a';
    }
    return c;//必须加上这一句，万一没有进if就没有return了
}
int main() {
    string s;
    cin>>s;
    int flag=-1;
    int len=s.length();//s.length和s.size()返回值类型都是无符号整型，需要先转为int才可以相加减
    for(int i=0;i<=len-3;i++){
        char a1=tolow(s[i]);
        char a2=tolow(s[i+1]);
        char a3=tolow(s[i+2]);
        if(a1=='b'&&a2=='o'&&a3=='b'){
            flag=i;
            break;
        }
    }
    cout<<flag<<endl;
    return 0;
}