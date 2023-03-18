#include <iostream>
#define TAM 50

using namespace std;

class Pila {
    private:
        char datos[TAM];
        int ult;
        bool inserta(char, int);
        bool elimina(int);
        char recupera(int)const;
        int primero()const;
        int ultimo()const;
        void imprime()const;
    public:
        Pila():ult(-1) {}
        bool vacia()const;
        bool llena()const;
        int buscar(char);
        void push(char);
        char pop();
        char top()const;
    };

char Pila::top()const {
    return datos[ult];
    }

char Pila::pop() {
    char val = '\0';
    if(!vacia()) {
        val = datos[ult--];;
        }

    return val;
    }

void Pila::push(char elem) {
    if(!llena()) {
        datos[++ult]= elem;
        }
    }

int Pila::buscar(char elem) {
    int i=0;
    while(i<=ult) {
        if(elem ==datos[i]) {
            return i;
            }
        i++;
        }
    return -1;
    }

void Pila::imprime()const {
    if(!vacia()) {
        char x;
        for(int i=0; i<=ult; i++) {
            x=datos[i];
            std::cout<<x<<std::endl;
            }
        }
    }

bool Pila::vacia()const {
    return ult==-1;
    }
bool Pila::llena()const {
    return ult==TAM-1;
    }

bool Pila::inserta(char elem, int pos) {
    if(llena() || pos<0 || pos>ult+1) {
        std::cout<<"\n No se pudo insertar";
        return false;
        }
    int i=ult+1;
    while(i>pos) {
        datos[i]=datos[i-1];
        i--;
        }
    datos[pos]=elem;
    ult++;
    return true;
    }

bool Pila::elimina(int pos) {
    if(vacia() || pos<0 || pos>ult) {
        std::cout<<"\n No se pudo eliminar";
        return false;
        }
    int i=pos;
    while(i<ult) {
        datos[i]=datos[i+1];
        i++;
        }
    ult--;
    return true;
    }

char Pila::recupera(int pos)const {
    if(vacia() || pos<0 || pos>ult-1) {
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
        }
    else {
        return datos[pos];
        }
    }

int Pila::primero()const {
    if(vacia()) {
        return -1;
        }
    return 0;
    }
int Pila::ultimo()const {
    if(vacia()) {
        return -1;
        }
    return ult;
    }

void postfix(char ei[], char ep[]) {
    Pila pa;

    int i = 0,j=0;
    while(ei[i] != '\0') {
        if(ei[i] >= 'a' && ei[i] <= 'z' || ei[i]>='A' && ei[i] <= 'Z') {
            ep[j] = ei[i];
            i++;
            j++;
            }
        else if(ei[i]=='(') {
            pa.push(ei[i]);
            i++;
            }
        else if(ei[i]==')') {
            while( pa.top() != '(') {
                ep[j]= pa.pop();
                j++;
                }
            if(pa.top() == '(') {
                pa.pop();
                }
            i++;
            }
        else if(ei[i]=='+' || ei[i]=='-' || ei[i]=='*' || ei[i]=='/') {
            if(ei[i]=='+' || ei[i] == '-') {
                while(!pa.vacia() && pa.top() != '(') {
                    ep[j]=pa.pop();
                    j++;
                    }
                pa.push(ei[i]);
                i++;
                }
            else {
                if(ei[i]=='*' || ei[i]=='/') {
                    while(!pa.vacia() && pa.top() != '(' && (pa.top()=='*'|| pa.top()=='/')) {
                        ep[j]=pa.pop();
                        j++;
                        }

                    pa.push(ei[i]);
                    i++;
                    }
                }
            }
        else {
            cout<<"caracteres invalidos"<<endl;
            ei[i] = '\0';
            }
        }
    while(!pa.vacia()) {
        ep[j]=pa.pop();
        j++;
        }
    ep[j] = '\0';
    }

int main () {

    char infija[TAM];
    char posfija[TAM];

    cout << "\nEscribe tu expresion en infix:" << endl;
    cin.getline (infija, TAM-1);
    postfix(infija, posfija);
    cout << "\nLa cadena infija \n"  << infija << endl;
    cout << "\nConvertida en postfija es: \n"  << posfija << endl;

    return 0;
    }
