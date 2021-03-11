/*
	Конкатенация и поворот
На словах определены операции конкатенации · и поворота R. Конкатенация склеивает два слова в одно: для слов u = ab и v = abb их конкатенация есть u·v = uv = ababb. Операция поворота переставляет буквы слова в обратном порядке: uR = ba, vR = bba, (uv)R = bbaba. Заметим, что для любых u и v, (uv)R = (vR)(uR).
На вход задачи подаётся дерево, каждый узел которого является операцией конкатенации. К некоторым узлам применена операция поворота – слово, которое окажется вычисленным в узле необходимо повернуть, прежде чем продолжать вычисление. Необходимо вычислить получившееся в корне слово.
	Input format
Деревья закодированы скобочными выражениями. Если у узла есть потомки, то потомки перечислены через запятую. Если к узлу применяется операция поворота, то она записана после закрывающей скобки. Длина описания дерева не превосходит 10000 символов. В листьях записаны слова.
	Output format
слово
	Examples
Input		Output
((ab)R,(abb))
		baabb
((ab)R,(abb))R
		bbaab
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cnt = 0;

class node {
	public:
	node *parent;
	string str;
	vector <node> children;
	node(node* par) {
		parent = par;
		str = "";
	}
	node(char ch) {
		str += ch;
	}
	node (string s) {
		str += s;
	}
};

void createTree (node *par) {
	node *elem;
	string swp;
	char ch;
	while (cin >> ch) {
		switch (ch) {
			case '(':
				elem = new node(par);
				par->children.push_back(elem);
				break;
			case ')':
                    cout << par->children[0].str << endl;
			// case 'R':
            //     elem = par;
			//     for (int i = elem->children.back()->str.size()-1; i >= 0; i--) {
			//       	    swp += elem->children.back()->str[i];
			//     }
			//     elem->children.back()->str = swp;
            //     cout << "swp " << elem->children.back()->str;
			// 	break;	
            // case ',':
            //     break;
            default :
				cout << ch << endl;
				par->children.push_back(ch);
			break;
		}
	}
}


int main () {	
	char ch;
	node *root;
	createTree(root);
	
	return 0;
}