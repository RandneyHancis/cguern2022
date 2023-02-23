#include <iostream>
#include "graphics.h"
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int p1[2], p2[2], OP, XMAX, YMAX;
float COS30 = 0.866, SEN30 = 0.5, SENN30 = -0.5;
float PI = 3.14;
//pontos do triangulo
float pt1[3] = {55, 90, 1}, pt2[3] = {40, 50, 1}, pt3[3] = {70, 50, 1}, pArb[2] = {55, 65};
bool tri == false;

//prototipos das funcoes
void Grade(int x, int y, int c);
int menu();
int menuTri();
void CasesMenu(int op);
void Escrever(int x, int y);
void RetaGeral(int p1[2], int p2[2]);
void DDA(float p1[2], float p2[2], bool tri);
void Bresenham(int p1[2], int p2[2]);
void Triagulo(float pt1[2], float pt2[2], float pt3[2], bool tri);
void Escala(float pt1[2], float pt2[2], float pt3[2]);
void Rotacao30(float pt1[2], float pt2[2], float pt3[2]);
void Translacao(float pt1[2], float pt2[2], float pt3[2]);
void Espelhamento(float pt1[2], float pt2[2], float pt3[2]);
void EscalaRotacao(float pt1[3], float pt2[3], float pt3[3]);
void EscalaArb(float pt1[3], float pt2[3], float pt3[3]);
void RotacaoArb(float pt1[3], float pt2[3], float pt3[3]);
void circuloParametrico(int r, int cor);
void simetriaOrdem8(int x, int y, int xc, int yc, int cor);
void circParametricaOrdem8(int r, int cor);
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
	/*while (OP != 5) {
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
			tri = false;
			DDA(p1, p2, tri);
			break;
		case 3:
			cout << "Digite o ponto inicial da reta: ";
			cin >> p1[0] >> p1[1];
			cout << "Digite o ponto final da reta: ";
			cin >> p2[0] >> p2[1];
			Bresenham(p1, p2);
			break;
		case 4:
			OP = menuTri();
			Triagulo(pt1, pt2, pt3, tri);
			while (OP != 6){
				switch (OP){
				case 0:
					cleardevice();
					Grade(XMAX, YMAX, 20);
					Triagulo(pt1, pt2, pt3, tri);
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
					//escala e rotacao
					break:
				case 6:

				default:
					cout << "Opcao nao existe, escolha opcao exeistente!" << endl;
					system("pause");
					break;
				}
			}
		case 5:
			closegraph();
			exit;
		default:
			cout << "Opcao nao existe, escolha opcao existente!" << endl;
			system("pause");
			break;
		}
		system("cls");
		OP = menu();
	}*/

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
	cout << "Digite 5 para sair" << endl;
	cout << "\n======================================================" << endl;
	cout << "Opcao: ";
	cin >> Op;
	return (Op);
}

//funcao do submenu do triangulo
int menuTri(){
	int Op;
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
	cout << "Digite 7 para sair" << endl;
	cout << "\n======================================================" << endl;
	cout << "Opcao: ";
	cin >> Op;
	return (Op);
}

//funcao dos cases de menu
void CasesMenu(int op){
	while (OP != 5) {
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
			tri = false;
			DDA(p1, p2, tri);
			break;
		case 3:
			cout << "Digite o ponto inicial da reta: ";
			cin >> p1[0] >> p1[1];
			cout << "Digite o ponto final da reta: ";
			cin >> p2[0] >> p2[1];
			Bresenham(p1, p2);
			break;
		case 4:
			OP = menuTri();
			Triagulo(pt1, pt2, pt3, tri);
			while (OP != 7){
				switch (OP){
				case 0:
					cleardevice();
					Grade(XMAX, YMAX, 20);
					Triagulo(pt1, pt2, pt3, tri);
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
					break:
				case 6:
					CasesMenu(op);
					break;
				case 7: 
					closegraph();
					exit;
				default:
					cout << "Opcao nao existe, escolha opcao exeistente!" << endl;
					system("pause");
					break;
				}
			}
		case 5:
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
void DDA(float p1[2], float p2[2], bool tri) {//observar tipo de variavel
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
	if(tri == false) { //se for linha
		for (int i = 0; i <= decide; i++) {
			putpixel(round(X), YMAX - round(Y), CYAN);
			X += Xinc; //incremento de x em cada passo
			Y += Yinc; //incremento de y em cada passo
			delay(50);
		}
	}else{ //se for um tringulo
		for (int i = 0; i <= decide; i++) {
			putpixel(round(X + XMAX/2), round(YMAX/2 - Y), CYAN);
			X += Xinc; //incremento de x em cada passo
			Y += Yinc; //incremento de y em cada passo
			delay(50);
		}
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
void Triagulo(float pt1[2], float pt2[2], float pt3[2], bool tri){
	DDA(pt1, pt2, tri);
	DDA(pt1, pt3, tri);
	DDA(pt2, pt3, tri);
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
	Triagulo(pt1, pt2, pt3, tri);
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

	Triagulo(pt1, pt2, pt3, tri);
}

//funcao de Translacao com fator (-3, 4)
void Translacao(float pt1[2], float pt2[2], float pt3[2]){
	pt1[0] = pt1[0] + (-3);
	pt1[1] = pt1[1] + 4;

	pt2[0] = pt2[0] + (-3);
	pt2[1] = pt2[1] + 4;
	
	pt3[0] = pt3[0] + (-3);
	pt3[1] = pt3[1] + 4;
	Triagulo(pt1, pt2, pt3, tri);
}

//funcao de Espelhamento em relação ao eixo x
void Espelhamento(float pt1[2], float pt2[2], float pt3[2]){
	pt1[1] = pt1[1] * (-1);
	pt2[1] = pt2[1] * (-1);
	pt3[1] = pt3[1] * (-1);
	Triagulo(pt1, pt2, pt3, tri);
}
//funcao de Escala e Rotacao (ponto arbitrario (55, 65)) 
void EscalaRotacao(float pt1[3], float pt2[3], float pt3[3]){
	EscalaArb(pt1, pt2, pt3);
	EscalaRotacao(pt1, pt2, p3);
	Triagulo(pt1, pt2, pt3, tri);
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
void circuloParametrico(int r, int cor){
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
}

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
	xc = XMAX / 2;
	yc = YMAX / 2;
	t = 1 / (double)r;
	x = double(r);
	y = 0;
	double c = cos(t);
	double s = sin(t);
	
	while(y <= x){
		xr = (int)round(x);
		yr = (int)round(y);
		simetriaOrdem8(xr, yr, xc, yc, WHITE);
		x = x * c - y * s;
		y = y * c + x * s;
	}
}

//fim das funcoes da circunferencia