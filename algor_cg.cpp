#include <iostream>
#include "graphics.h"
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int p1[2], p2[2], OP, XMAX, YMAX;

//prótotipos das funções
void Grade(int x, int y, int c);
int menu(); 
void Escrever(int x, int y);
void RetaGeral(int p1[2], int p2[2]);
void DDA(int p1[2], int p2[2]);
void Bresenham(int p1[2], int p2[2]);

int main() {
	XMAX = 700;
	YMAX = 490;
	initwindow(XMAX, YMAX, "Computação Grafica - Primitivas", 500, 0);
	setbkcolor(0);
	cleardevice();
	Grade(XMAX, YMAX, 20);
	OP = menu();	

	while (OP != 4) {
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

	return 0;
}

//funções

//função do menu de escolha
int menu() {
	int Op;
	cout << "======================================================" << endl;
	cout << "                 Escolha uma opcao                    " << endl;
	cout << "======================================================" << endl;
	cout << "Digite 0 para limpar a tela" << endl;
	cout << "Digite 1 para Reta Geral" << endl;
	cout << "Digite 2 para Reta DDA" << endl;
	cout << "Digite 3 para Reta Bresenham" << endl;
	cout << "Digite 4 para sair" << endl;
	cout << "\n======================================================" << endl;
	cout << "Opcao: ";
	cin >> Op;
	return (Op);
}


//função de desenhar uma grade na tela
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

//Função para mostrar os pontos escritos na tela
void Escrever(int x, int y) {
	char cx[10], cy[10];
	itoa(x, cx, 10); //converte int em string
	itoa(y, cy, 10);
	setcolor(WHITE); //cor dos numeros
	outtextxy(x, YMAX - y, cx); //mostra a escrita em um ponto da tela
	outtextxy(x + 30, YMAX - y, cy);
}

//Função geral da reta
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

//Função da Digital Differential Analyser (DDA)
void DDA(int p1[2], int p2[2]) {
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

//Função de Bresenham
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