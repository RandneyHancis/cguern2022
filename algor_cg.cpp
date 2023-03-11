#include <iostream>
#include "graphics.h"
#include <stdlib.h>
#include <ctype.h>

using namespace std;

class point
{
public:
	int x, y;
};
class poly
{
private:
	point p[20];
	int inter[20], x, y;
	int v, xmin, ymin, xmax, ymax;
public:
	int c;
	void lados();
	void calcs();
	void display();
	void ints(float);
	void preenche(int);
};

int p1[2], p2[2], OP, OPt, OPc, XMAX, YMAX, raio, raioX, raioY;
float pdda1[2], pdda2[2];
float COS30 = 0.866, SEN30 = 0.5, SENN30 = -0.5;
float PI = 3.14;
//pontos do triangulo
float pt1[3] = { 55, 90, 1 }, pt2[3] = { 40, 50, 1 }, pt3[3] = { 70, 50, 1 }, pArb[2] = { 55, 65 };
poly x;

//prototipos das funcoes
void Grade(int x, int y, int c);
int menu();
int menuTri();
void CasesMenu(int op);
void Escrever(int x, int y);
void RetaGeral(int p1[2], int p2[2]);
void DDA(int p1[2], int p2[2]);
void DDATri(float p1[2], float p2[2]);
void Bresenham(int p1[2], int p2[2]);
void Triagulo(float pt1[2], float pt2[2], float pt3[2]);
void Escala(float pt1[2], float pt2[2], float pt3[2]);
void Rotacao30(float pt1[2], float pt2[2], float pt3[2]);
void Translacao(float pt1[2], float pt2[2], float pt3[2]);
void Espelhamento(float pt1[2], float pt2[2], float pt3[2]);
void EscalaRotacao(float pt1[3], float pt2[3], float pt3[3]);
void EscalaArb(float pt1[3], float pt2[3], float pt3[3]);
void RotacaoArb(float pt1[3], float pt2[3], float pt3[3]);
//void circuloParametrico(int r, int cor);
void simetriaOrdem8(int x, int y, int xc, int yc, int cor);
void circParametricaOrdem8(int r, int cor);
void circPontoMedio(int r, int cor);
void elipsePontoMedio(int raioX, int raioY, int cor);
//fim dos prototipos das funcoes

int main() {
	XMAX = 700;
	YMAX = 490;
	initwindow(XMAX, YMAX, "Computacao Grafica - Primitivas", 500, 0);
	setbkcolor(0);
	cleardevice();
	Grade(XMAX, YMAX, 20);
	OP = menu();	
	CasesMenu(OP);

	return 0;
}

//funcoes

//funcao do menu de escolha principal
int menu() {
	int Op;
	cout << "======================================================" << endl;
	cout << "                 Escolha uma opcao                    " << endl;
	cout << "======================================================" << endl;
	cout << "Digite 0 para limpar a tela" << endl;
	cout << "Digite 1 para Reta Geral" << endl;
	cout << "Digite 2 para Reta DDA" << endl;
	cout << "Digite 3 para Reta Bresenham" << endl;
	cout << "Digite 4 para abrir menu do triangulo" << endl;
	cout << "Digite 5 para abrir o menu da circunferencia" << endl;
	cout << "Digite 6 para desenhar um poligono concavo preenchido" << endl;
	cout << "Digite 7 para sair" << endl;
	cout << "\n======================================================" << endl;
	cout << "Opcao: ";
	cin >> Op;
	return (Op);
}

//funcao do submenu do triangulo
int menuTri(){
	int Op2;
	cout << "======================================================" << endl;
	cout << "                 Escolha uma opcao                    " << endl;
	cout << "======================================================" << endl;
	cout << "Digite 0 para limpar a tela" << endl;
	cout << "Digite 1 para Fator de escala (2, 2)" << endl;
	cout << "Digite 2 para Rotacao de 30 graus" << endl;
	cout << "Digite 3 para Translacao com fator (-3, 4)" << endl;
	cout << "Digite 4 para Espelhamento em relação ao eixo x" << endl;
	cout << "Digite 5 para Escala e Rotacao (ponto arbitrario (55, 65))" << endl;
	cout << "Digite 6 para voltar ao menu principal" << endl;
	cout << "\n======================================================" << endl;
	cout << "Opcao: ";
	cin >> Op2;
	return (Op2);
}

//funcao do submenu da circunferencia
int menuCirc() {
	int Op3;
	cout << "======================================================" << endl;
	cout << "                 Escolha uma opcao                    " << endl;
	cout << "======================================================" << endl;
	cout << "Digite 0 para limpar a tela" << endl;
	cout << "Digite 1 para circunferencia com algor. parametrico" << endl;
	cout << "Digite 2 para circunferencia com algor. do ponto medio" << endl;
	cout << "Digite 3 para circunferencia preenchida" << endl;
	cout << "Digite 4 para desenhar uma elipse preenchida" << endl;
	cout << "Digite 5 para voltar ao menu principal" << endl;
	cout << "\n======================================================" << endl;
	cout << "Opcao: ";
	cin >> Op3;
	return (Op3);
}

//funcao dos cases de menu
void CasesMenu(int op){
	while (OP != 7) {
		switch (OP){
		case 0:
			cleardevice();
			Grade(XMAX, YMAX, 20);
			break;
		case 1:
			cout << "Digite o ponto inicial da reta: ";
			cin >> p1[0] >> p1[1];
			cout << "Digite o ponto final da reta: ";
			cin >> p2[0] >> p2[1];
			RetaGeral(p1, p2);
			break;
		case 2:
			cout << "Digite o ponto inicial da reta: ";
			cin >> p1[0] >> p1[1];
			cout << "Digite o ponto final da reta: ";
			cin >> p2[0] >> p2[1];
			DDA(p1, p2);
			break;
		case 3:
			cout << "Digite o ponto inicial da reta: ";
			cin >> p1[0] >> p1[1];
			cout << "Digite o ponto final da reta: ";
			cin >> p2[0] >> p2[1];
			Bresenham(p1, p2);
			break;
		case 4:
			system("cls");			
			Triagulo(pt1, pt2, pt3);
			OPt = menuTri();
			while (OPt != 6){
				switch (OPt){
				case 0:
					cleardevice();
					Grade(XMAX, YMAX, 20);
					Triagulo(pt1, pt2, pt3);
					break;
				case 1:					
					Escala(pt1, pt2, pt3);
					break;
				case 2:
					Rotacao30(pt1, pt2, pt3);
					break;
				case 3:
					Translacao(pt1, pt2, pt3);
					break;
				case 4:
					Espelhamento(pt1, pt2, pt3);
					break;
				case 5:
					EscalaRotacao(pt1, pt2, pt3);
					break;				
				case 6: 
					closegraph();
					exit;
				default:
					cout << "Opcao nao existe, escolha opcao existente!" << endl;
					system("pause");
					break;
				}
				system("cls");
				OPt = menuTri();
			}
			break;
		case 5:
			system("cls");
			OPc = menuCirc();						
			while (OPc != 5) {
				switch (OPc){
				case 0:
					cleardevice();
					Grade(XMAX, YMAX, 20);					
					break;
				case 1:
					cout << "Qual o raio da circunferencia: ";
					cin >> raio;
					circParametricaOrdem8(raio, YELLOW);
					break;
				case 2:
					cout << "Qual o raio da circunferencia: ";
					cin >> raio;
					circPontoMedio(raio, GREEN);
					break;
				case 3:
					cout << "Qual o raio da circunferencia: ";
					cin >> raio;					
					while (raio > 0) { //para preencher o circulo
						circPontoMedio(raio, GREEN);
						raio--;
					}
					break;
				case 4:
					cout << "Qual o raio vertical da elipse: ";
					cin >> raioX;
					cout << "Qual o raio horizontal da elipse: ";
					cin >> raioY;
					
					while (raioX >= 0) { //para preencher a elipse
						elipsePontoMedio(raioX, raioY, GREEN);
						raioX--;
						raioY--;
					}
					break;
				case 5:
					closegraph();
					exit;
				default:
					cout << "Opcao nao existe, escolha opcao existente!" << endl;
					system("pause");
					break;
				}
				system("cls");
				OPc = menuCirc();
			}
			break;
		case 6:			
			x.lados();
			x.calcs();
			cleardevice();
			setcolor(GREEN);
			x.display();
			break;
		case 7:
			closegraph();
			exit;
		default:
			cout << "Opcao nao existe, escolha opcao existente!" << endl;
			system("pause");
			break;
		}
		system("cls");
		OP = menu();
	}

}

//funcao de desenhar uma grade na tela
void Grade(int x, int y, int c) {
	setcolor(RED);
	for (int i = 0; i <= y; i = i + c) { //linhas horizontais
		line(0, i, x + i, i);
		//delay(50);
	}
	for (int j = 0; j <= x; j = j + c) { //linhas verticais
		line(j, 0, j, y + j);
		//delay(50);
	}
}

//Funcao para mostrar os pontos escritos na tela
void Escrever(int x, int y) {
	char cx[10], cy[10];
	itoa(x, cx, 10); //converte int em string
	itoa(y, cy, 10);
	setcolor(WHITE); //cor dos numeros
	outtextxy(x, YMAX - y, cx); //mostra a escrita em um ponto da tela
	outtextxy(x + 30, YMAX - y, cy);
}

//Funcao geral da reta
void RetaGeral(int p1[2], int p2[2]) {
	int x, x1, x2, y, y1, y2, m, b;
	x1 = p1[0];
	y1 = p1[1];
	x2 = p2[0];
	y2 = p2[1];
	Escrever(x1, y1);
	Escrever(x2, y2);
	
	if (x1 == x2) {
		for (y = y1; y < y2; y++) {
			putpixel(x1, YMAX - y, WHITE);
			delay(50);
		}
	}
	else {
		m = (y2 - y1) / (x2 - x1);
		b = y2 - m * x2;
		for (x = x1; x < x2; x++) {
			y = m * x + b;
			putpixel(x, YMAX - y, WHITE);
			delay(50);
		}
	}
}

//Funcao da Digital Differential Analyser (DDA)
void DDA(int p1[2], int p2[2]) {//observar tipo de variavel
	//calculo do dx e dy

	int dx = p2[0] - p1[0];
	int dy = p2[1] - p1[1];
	Escrever(p1[0],p1[1]);
	Escrever(p2[0], p2[1]);

	//gerar pixels
	int decide = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	//calcula o incremento em x e em y para cada passo
	float Xinc = dx / (float)decide;
	float Yinc = dy / (float)decide;

	//escreve o pixel em cada passo
	float X = p1[0];
	float Y = p1[1];
	for (int i = 0; i <= decide; i++) {
		putpixel(round(X), YMAX - round(Y), CYAN);
		X += Xinc; //incremento de x em cada passo
		Y += Yinc; //incremento de y em cada passo
		delay(50);
	}
}

void DDATri(float p1[2], float p2[2]) {
	//calculo do dx e dy

	int dx = p2[0] - p1[0];
	int dy = p2[1] - p1[1];
	
	//gerar pixels
	int decide = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	//calcula o incremento em x e em y para cada passo
	float Xinc = dx / (float)decide;
	float Yinc = dy / (float)decide;

	//escreve o pixel em cada passo
	float X = p1[0];
	float Y = p1[1];
	for (int i = 0; i <= decide; i++) {
		putpixel(round(X + XMAX / 2), round(YMAX / 2 - Y), CYAN);
		X += Xinc; //incremento de x em cada passo
		Y += Yinc; //incremento de y em cada passo
		//delay(50);
	}
}

//Funcao de Bresenham para linha
void Bresenham(int p1[2], int p2[2]) {
	int x, y, x1, x2, y1, y2, xf;
	float P, P2, Dx, Dy, xy2;
	x1 = p1[0];
	x2 = p2[0];
	y1 = p1[1];
	y2 = p2[1];
	Escrever(x1, y1);
	Escrever(x2, y2);
	Dx = abs(x1 - x2);
	Dy = abs(y1 - y2);
	P = 2 * Dy - Dx;

	if (x1 > x2) {
		x = x2;
		y = y2;
		xf = x1;
	}
	else {
		x = x1;
		y = y1;
		xf = x2;
	}
	putpixel(x, YMAX - y, YELLOW);
	delay(50);

	while (x < xf) {
		x++;
		if (P < 0) {
			P = P + 2 * Dy;
		}
		else {
			y++;
			P = P + 2 * (Dy - Dx);
		}
		putpixel(x, YMAX - y, YELLOW);
		delay(50);
	}
}

//funcao para desenha triangulo
void Triagulo(float pt1[2], float pt2[2], float pt3[2]){
	DDATri(pt1, pt2);
	DDATri(pt1, pt3);
	DDATri(pt2, pt3);
}

//funcoes do tringulo
//funcao de Fator de escala (2, 2)
void Escala(float pt1[2], float pt2[2], float pt3[2]){
	pt1[0] = pt1[0] * 2;
	pt1[1] = pt1[1] * 2;

	pt2[0] = pt2[0] * 2;
	pt2[1] = pt2[1] * 2;
	
	pt3[0] = pt3[0] * 2;
	pt3[1] = pt3[1] * 2;
	Triagulo(pt1, pt2, pt3);
}

//funcao de Rotacao de 30 graus
void Rotacao30(float pt1[2], float pt2[2], float pt3[2]){
	float aux = 0.0;
	aux = pt1[0] * COS30 + pt1[1] * SENN30;
	pt1[1] = pt1[0] * SEN30 + pt1[1] * COS30;
	pt1[0] = aux;

	aux = pt2[0] * COS30 + pt2[1] * SENN30;
	pt2[1] = pt2[0] * SEN30 + pt2[1] * COS30;
	pt2[0] = aux;

	aux = pt3[0] * COS30 + pt3[1] * SENN30;
	pt3[1] = pt3[0] * SEN30 + pt3[1] * COS30;
	pt3[0] = aux;

	Triagulo(pt1, pt2, pt3);
}

//funcao de Translacao com fator (-3, 4)
void Translacao(float pt1[2], float pt2[2], float pt3[2]){
	pt1[0] = pt1[0] + (-3);
	pt1[1] = pt1[1] + 4;

	pt2[0] = pt2[0] + (-3);
	pt2[1] = pt2[1] + 4;
	
	pt3[0] = pt3[0] + (-3);
	pt3[1] = pt3[1] + 4;
	Triagulo(pt1, pt2, pt3);
}

//funcao de Espelhamento em relação ao eixo x
void Espelhamento(float pt1[2], float pt2[2], float pt3[2]){
	pt1[1] = pt1[1] * (-1);
	pt2[1] = pt2[1] * (-1);
	pt3[1] = pt3[1] * (-1);
	Triagulo(pt1, pt2, pt3);
}
//funcao de Escala e Rotacao (ponto arbitrario (55, 65)) 
void EscalaRotacao(float pt1[3], float pt2[3], float pt3[3]){
	EscalaArb(pt1, pt2, pt3);
	EscalaRotacao(pt1, pt2, pt3);
	Triagulo(pt1, pt2, pt3);
}

//funcao escala com ponto fixo arbitrario
void EscalaArb(float pt1[3], float pt2[3], float pt3[3]){
	//ponto a
	pt1[0] = pt1[0] * 2 + pt1[1] * 0 + pt1[2] * pArb[0] * (1 - 2);
	pt1[1] = pt1[0] * 0 + pt1[1] * 2 + pt1[2] * pArb[1] * (1 - 2);
	pt1[2] = pt1[0] * 0 + pt1[1] * 0 + pt1[2] * 1;
	//ponto b
	pt2[0] = pt1[0] * 2 + pt1[1] * 0 + pt1[2] * pArb[0] * (1 - 2);
	pt2[1] = pt1[0] * 0 + pt1[1] * 2 + pt1[2] * pArb[1] * (1 - 2);
	pt2[2] = pt1[0] * 0 + pt1[1] * 0 + pt1[2] * 1;
	//ponto c
	pt3[0] = pt1[0] * 2 + pt1[1] * 0 + pt1[2] * pArb[0] * (1 - 2);
	pt3[1] = pt1[0] * 0 + pt1[1] * 2 + pt1[2] * pArb[1] * (1 - 2);
	pt3[2] = pt1[0] * 0 + pt1[1] * 0 + pt1[2] * 1;
}

//funcao rotacao 30 com ponto fixo arbitrario
void RotacaoArb(float pt1[3], float pt2[3], float pt3[3]){
	//ponto a
	pt1[0] = (pt1[0] * COS30) + (pt1[1] * SENN30) + (pt1[2] * pArb[0] * (1 - COS30) + pArb[1] * SEN30);
	pt1[1] = (pt1[0] * COS30) + (pt1[1] * SENN30) + (pt1[2] * pArb[1] * (1 - COS30) - pArb[0] * SEN30);
	pt1[2] = (pt1[0] * 0) + (pt1[1] * 0) + pt1[2] * 1;
	//ponto b
	pt2[0] = (pt1[0] * COS30) + (pt1[1] * SENN30) + (pt1[2] * pArb[0] * (1 - COS30) + pArb[1] * SEN30);
	pt2[1] = (pt1[0] * COS30) + (pt1[1] * SENN30) + (pt1[2] * pArb[1] * (1 - COS30) - pArb[0] * SEN30);
	pt2[2] = (pt1[0] * 0) + (pt1[1] * 0) + pt1[2] * 1;
	//ponto c
	pt3[0] = (pt1[0] * COS30) + (pt1[1] * SENN30) + (pt1[2] * pArb[0] * (1 - COS30) + pArb[1] * SEN30);
	pt3[1] = (pt1[0] * COS30) + (pt1[1] * SENN30) + (pt1[2] * pArb[1] * (1 - COS30) - pArb[0] * SEN30);
	pt3[2] = (pt1[0] * 0) + (pt1[1] * 0) + pt1[2] * 1;

}
//fim funcoes do tringulo

//inicio das funcoes da circunferencia
//funcao da equacao parametrica
/*void circuloParametrico(int r, int cor) {
	int x, y, xc, yc;
	xc = XMAX / 2;
	yc = YMAX / 2;
	float t;
	x = r;
	y = 0;

	for(t = 1; y < 360; t = t + 0.1){
		putpixel(x + xc, y + yc, WHITE);
		x = r * cos(PI * t / 180);
		y = r * sin(PI * t / 180);
	}
}*/

//funcao dos 8 pontos de 45 graus do circulo
void simetriaOrdem8(int x, int y, int xc, int yc, int cor){
	putpixel(x + xc, y + yc, cor);
	putpixel(y + xc, x + yc, cor);
	putpixel(-y + xc, x + yc, cor);
	putpixel(-x + xc, y + yc, cor);
	putpixel(-x + xc, -y + yc, cor);
	putpixel(-y + xc, -x + yc, cor);
	putpixel(y + xc, -x + yc, cor);
	putpixel(x + xc, -y + yc, cor);
}

//funcao circunferencia parametrica usando a simetria de ordem 8
void circParametricaOrdem8(int r, int cor){
	int xc, yc, xr, yr;
	double x, y, t;
	xc = XMAX / 2; //x centro da circunferência
	yc = YMAX / 2; //y centro da circunferência
	t = 1 / (double)r;
	x = double(r);
	y = 0;
	double c = cos(t);
	double s = sin(t);
	
	while(y <= x){
		xr = (int)round(x);
		yr = (int)round(y);
		simetriaOrdem8(xr, yr, xc, yc, WHITE);
		x = x * c - y * s; //próximo x
		y = y * c + x * s; //próximo y
	}
}

//funcao ponto médio - curcunferência
void circPontoMedio(int r, int cor) {
	int xc, yc;
	xc = XMAX / 2;
	yc = YMAX / 2;
	int x = 0;
	int y = r;
	double d = 5 / 4 - r;
	simetriaOrdem8(x, y, xc, yc, cor);
	while (y > x) {
		if (d < 0) {
			d = d + 2.0 * x + 3.0;
		}
		else {
			d = d + 2.0 * (x - y) + 5;
			y--;
		}
		x++;
		simetriaOrdem8(x, y, xc, yc, cor);
	}
}

//funcao da elipse
void elipsePontoMedio(int raioX, int raioY, int cor){
	int xc, yc;
	xc = XMAX / 2;
	yc = YMAX / 2;
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = raioY;

	//parametro de decisao inicial regiao 1
	d1 = (raioY * raioY) - (raioX * raioX * raioY) + (0.25 * raioX * raioX);
	dx = 2 * raioY * raioY * x;
	dy = 2 * raioX * raioX * y;

	//simetria de ordem 8 para a regiao 1 com espelhamento
	while(dx < dy){
		simetriaOrdem8(x, xc, y, yc, cor); //lado direito
		simetriaOrdem8(x * -1, xc, y * -1, yc, cor); //lado esquerdo
		
		//checa e atualiza valor de parametro de decisão
		//baseado no algoritmo
		if(d1 < 0){
			x++;
			dx = dx + (2 * raioY * raioY);
			d1 = d1 + dx + (raioY * raioY);
		}else{
			x++;
			y--;
			dx = dx + (2 * raioY * raioY);
			dy = dy - (2 * raioX * raioX);
			d1 = d1 + dx - dy + (raioY * raioY);
		}
	}

	//parametro de decisao inicial regiao 2
	d2 = ((raioY * raioY) * ((x + 0.5) * (x + 0.5))) + 
		 ((raioX * raioX) * ((y - 1) * (y - 1))) - 
		 (raioX * raioX * raioY * raioY);
	
	//simetria de ordem 8 para a regiao 2 com espelhamento
	while (y >= 0) {
		simetriaOrdem8(x, xc, y, yc, cor); //lado direito
		simetriaOrdem8(x * -1, xc, y * -1, yc, cor); //lado esquerdo

		//checa e atualiza valor de parametro de decisão
		//baseado no algoritmo
		if(d2 > 0){
			y--;
			dy = dy - (2 * raioX * raioX);
			d2 = d2 + (raioX * raioX) - dy;
		}else{
			y--;
			x++;
			dx = dx + (2 * raioY * raioY);
			dy = dy - (2 * raioX * raioX);
			d2 = d2 + dx - dy + (raioX * raioX);
		}
	}
}
//fim função elipse

//fim das funcoes da circunferencia

//inicio das funcoes do poligono concavo
void poly::lados(){ //verifica se o poligono e aceitavel e faz a escolha dos pontos
	int i;
	cout << "\n Numero de vertices do poligono: ";
	cin >> v;
	if (v > 2) 
	{
		for (i = 0; i < v; i++)
		{
			cout << "\nCoordenada " << i + 1 << " : ";
			cout << "\n\tx" << (i + 1) << "=";
			cin >> p[i].x;
			cout << "\n\ty" << (i + 1) << "=";
			cin >> p[i].y;
		}
		p[i].x = p[0].x;
		p[i].y = p[0].y;
		xmin = xmax = p[0].x;
		ymin = ymax = p[0].y;
	}
	else
		cout << "\n Escolha numero valido de vertices";
}

void poly::calcs()
{
	for (int i = 0; i < v; i++)
	{
		if (xmin > p[i].x)
			xmin = p[i].x;
		if (xmax < p[i].x)
			xmax = p[i].x;
		if (ymin > p[i].y)
			ymin = p[i].y;
		if (ymax < p[i].y)
			ymax = p[i].y;
	}
}

void poly::display(){	
	float s;

	s = ymin + 0.01;
	delay(25);
	cleardevice();
	while (s <= ymax){
		ints(s);
		preenche(s);
		s++;
	}	
}

void poly::ints(float z){
	int x1, x2, y1, y2, temp;
	c = 0;
	for (int i = 0; i < v; i++){
		x1 = p[i].x;
		y1 = p[i].y;
		x2 = p[i + 1].x;
		y2 = p[i + 1].y;
		if (y2 < y1){
			temp = x1;
			x1 = x2;
			x2 = temp;
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		if (z <= y2 && z >= y1){
			if ((y1 - y2) == 0)
				x = x1;
			else{
				x = ((x2 - x1) * (z - y1)) / (y2 - y1);
				x = x + x1;
			}
			if (x <= xmax && x >= xmin)
				inter[c++] = x;
		}
	}
}

void poly::preenche(int z){
	int j, i;
	for (i = 0; i < v; i++){
		line(p[i].x, p[i].y, p[i + 1].x, p[i + 1].y);
	}
	delay(25);
	for (i = 0; i < c; i += 2){
		delay(25);
		line(inter[i], z, inter[i + 1], z);
	}
}

//fim das funcoes do poligono concavo