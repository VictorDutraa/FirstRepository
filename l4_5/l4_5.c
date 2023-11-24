#include<stdio.h>
#include<math.h>

typedef struct{
    int x;
    int y;
    int quadrante;
} tPonto;

/*
(a) inicialização do ponto a partir de um x e um y dados;
(b) inicialização de ponto com coordenadas lidas da entrada padrão;
(c) apresentação das coordenadas do ponto na saída padrão com o formato “(x,y)”;
(d) alteração da abscissa x do ponto;
(e) alteração da ordenada y do ponto;
(f) obtenção da abscissa x do ponto;
(g) obtenção da ordenada y do ponto;
(h) movimentação do ponto por um delta x e um delta y;
(i) cálculo da distância entre dois pontos;

(j) identificação do quadrante do ponto 
(1, 2, 3 ou 4 para os quadrantes normais 
e 0 para pontos em cima dos eixos);

(k) obtenção do ponto simétrico a um ponto.
*/

void ImprimePonto(tPonto ponto){
    printf("(%d,%d) ",ponto.x,ponto.y);
}

tPonto AlteraX(tPonto p){
    tPonto ponto=p;
    ponto.x=ponto.x*(-1);
    return ponto;
}

tPonto AlteraY(tPonto p){
    tPonto ponto=p;
    ponto.y=ponto.y*(-1);
    return ponto;
}

int ObtemPontoX(tPonto p){
    return p.x;
}

int ObtemPontoY(tPonto p){
    return p.y;
}

tPonto MovimentaPonto(tPonto p){}

int IdentificaQuadrante(tPonto p){
    if(p.x>0 && p.y>0){
        return 1;
    }
    else if(p.x>0 && p.y<0){
        return 4;
    }
    else if(p.x<0 && p.y>0){
        return 2;
    }
    else if(p.x<0 && p.y<0){
        return 3;
    }
    else{
        return 0;
    }
}

tPonto RecebePonto(){
    tPonto ponto;
    scanf("%d %d", &ponto.x, &ponto.y);
    return ponto;
}

tPonto InicializaPonto(int x, int y){
    tPonto ponto;
    ponto.x=x;
    ponto.y=y;
    ponto.quadrante=0;
    return ponto;
}

void ImprimeQuadrante(int quadranteAtual){
    printf("%d ",quadranteAtual);
}

tPonto IdentificaSimetrico(tPonto ponto){
    tPonto p = ponto;
    p.x = p.x * -1;
    p.y = p.y * -1;
    return p;
}

float CalculoDistanciaPontos(tPonto pontoF, tPonto pontoI){
    float dist;
    //pontoF == x final e y final.
    dist = sqrt ( ((pontoF.x - pontoI.x)*(pontoF.x - pontoI.x)) + ( (pontoF.y - pontoI.y)*(pontoF.y - pontoI.y) ) );
    return dist;
}

int main(){
    
    int qtd;

    //tPonto final 
    tPonto ponto;
    tPonto ponto2;
    tPonto pontoB;
    tPonto pontoA;

    float distancia;
    int x1, x2, y1, y2;
    int xF, yF, xI, yI;

    scanf("%d",&qtd);
    
    
    if(qtd==1){
        printf("-\n");
    }

    qtd--;
    int inicio = qtd;

    while(qtd){

        if(inicio == qtd){
            ponto=RecebePonto();      
            ponto2=RecebePonto();
             printf("-\n");
        }
        else{
            //ponto1 recebe o antigo ponto2
            ponto = ponto2;
            //leio um novo ponto2
            ponto2 = RecebePonto();
        }
        x1 = ObtemPontoX(ponto);
        y1 = ObtemPontoY(ponto);  
        x2 = ObtemPontoX(ponto2);
        y2 = ObtemPontoY(ponto2);

        pontoA = InicializaPonto(x1, y1);
        pontoB = InicializaPonto(x2, y2);
        distancia = CalculoDistanciaPontos(pontoA, pontoB);

        
        printf("%.2f\n", distancia);
        
        qtd--;
    }

    return 0;
}



 





/*define-se as coordenadas iniciais e finais.
        if(x1 > x2){
            xF = x1;
            xI = x2;
        }
        else{
            xF = x2;
            xI = x1;
        }
        if(y1 > y2){
            yF = y1;
            yI = y2;
        }
        else{
            yF = y2;
            yI = y1;
        }*/

        //inicializar o ponto com as coordenadas finais e iniciais;
