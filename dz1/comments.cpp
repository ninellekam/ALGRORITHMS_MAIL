#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

int main() {
    enum STATE {START, COM1, COM2, COM3, STR, NET, FIN}
    STATE = START;
    unsigned int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    string s, s1;
    char c;
    while (getline(cin, s1)) {
        s1 += '\n';
        s += s1;
    }
    for (int i = 0; i < s.size() ; i++) {
        if (STATE == NET)
            STATE = START;
        if ( (STATE == START || STATE == FIN ) && (s[i+1] == '*' && s[i] == '('))
            STATE = COM1;
        else if ( (STATE == START || STATE == FIN) && (s[i] == '{'))
            STATE = COM2;
        else if ( (STATE == START || STATE == FIN ) && (s[i] == '/' && s[i+1]== '/') )
            STATE = COM3;
        else if ( (STATE == START || STATE == FIN) && s[i] == '\'') {
            STATE = STR;
        }
        else if ( ( (STATE == COM1 ) && (s[i+1] == ')' && s[i] == '*'))) {
            STATE = FIN; cnt1++;
        }
        else if ( ( (STATE == COM2) && s[i] == '}')) {
            STATE = FIN; cnt2++;
        }
        else if ( ( (STATE == COM3) && s[i] == '\n' )) {
            STATE = FIN; cnt3++;
        }
        else if (STATE == STR && s[i] == '\n')
            STATE = FIN;
        else if ( (STATE == STR) && s[i] == '\'' ) {
            STATE = FIN; cnt4++;
        }
        else if (STATE == START) {
            STATE = NET;
        }
    }
    cout << cnt1 << " " << cnt2 << " " << cnt3 << " " << cnt4 << endl;
    return (0);
}