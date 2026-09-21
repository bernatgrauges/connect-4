#define N 8

typedef struct node {
    struct node **fills;
    int n_fills;
    char tauler[N][N];
    int valor;
    int nivell;
    int columna;
} Node;

void posarZeros(char tauler[N][N]);
void imprimirTauler(char tauler[N][N]);
int horitzontal(char tauler[N][N],int fila,int torn,int punts);
int vertical(char tauler[N][N],int col,int torn,int punts);
int diagonalamunt(char tauler[N][N],int torn,int punts);
int diagonalavall(char tauler[N][N],int torn,int punts);
int condGuanyar(char tauler[N][N],int torn);
void gravetat(char tauler[N][N],int lloc,int torn);
void demanarTirada(char tauler[N][N],int contador,int *lloc,int modeDeJoc,int ordre);
int calculaNumFills(char tauler[N][N]);
void tirada(char tauler[N][N],int numDeFill, int nivell);
void copiaTauler(char tauler[N][N], char taulerc[N][N]);
int calculValor(Node *arrel);
Node* creaNode(Node *pare,int numDeFill, int nivell,int dificultat);
void creaNivell(Node *pare,int nivell,int dificultat);
void crearArbre(Node *arrel, int nivell, int dificultat);
void recorreArbreRec(Node *arrel,int nivell,int comptador);
int minimax(Node *arrel,int nivell);
int triarTiradaOrdinador(Node *arrel,char tauler[N][N],int dificultat);

