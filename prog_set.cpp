#include <unistd.h>
#include <bits/stdc++.h>
#define GetCurrentDir getcwd
using namespace std;
char get_dir(){
    char cCurrentPath[FILENAME_MAX];
    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))){
      return errno;
    }
    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';
    //printf ("The current working directory is %s", cCurrentPath);
    cout << cCurrentPath << endl;
}
/*void catalog_prep(string prog_name){
    system(("mkdir "+prog_name).c_str());
    cout << "Catalog " << prog_name << " created!\n";
    system(("cd "+prog_name).c_str());
}*/
void make_prep(string prog_name){
    system("touch Makefile");
    ofstream makefile;
    makefile.open("Makefile");
    makefile << "all:" << endl;
    makefile << "\tg++ "<< prog_name << ".cpp -std=gnu++1z -O2 -Wall -g ";
    makefile << "-o " << prog_name;
    makefile.close();
}
void file_prep(string prog_name){
    system("touch main.cpp");
    ofstream prog_file;
    prog_file.open("main.cpp");
    prog_file << "#include <bits/stdc++.h>" << endl;
    prog_file << "#include <unistd.h>" << endl;
    prog_file << "using namespace std;" << endl;
    prog_file << "int main(){" << endl;
    prog_file << "\tios_base::sync_with_stdio(0);" << endl;
    prog_file << "\treturn 0;\n";
    prog_file << "\t//Happy coding ^.^\n";
    prog_file << "}";
    prog_file.close();
    system (("mv main.cpp "+prog_name+".cpp").c_str());
    cout << "Files prepared!\n";
}
void tests(){
    system("touch tests");
}
int main(){
    string prog_name;
    cout << "Please give name of program: ";
    cin >> prog_name;
    make_prep(prog_name);
    file_prep(prog_name);
    tests();
    cout << "Current directory is: ";
    get_dir();
    return 0;
}
