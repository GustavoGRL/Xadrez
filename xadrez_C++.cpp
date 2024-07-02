#include<iostream>
#include<list>
#include<sstream>

void criando_tabuleiro(std:: string (&tabuleiro)[8][8]){
    
    // adicionado os espaços das peças. 
    
    for(int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            tabuleiro[i][j]="___ ";
           
        }
    }
    
    //emplementando as peças no tabuleiro
    
    //peão 
    for (int i=0; i<8; i++){
        tabuleiro[1][i]="_♙_ ";
        tabuleiro[6][i]="_♟_ ";
    }
    
    //torre
    tabuleiro[0][0]="_♖_ ";
    tabuleiro[0][7]="_♖_ ";
    tabuleiro[7][0]="_♜_ ";
    tabuleiro[7][7]="_♜_ ";
    
    //cavalo
    tabuleiro[0][1]="_♘_ ";
    tabuleiro[0][6]="_♘_ ";
    tabuleiro[7][1]="_♞_ ";
    tabuleiro[7][6]="_♞_ ";
    
    //clero
    tabuleiro[0][2]="_♗_ ";
    tabuleiro[0][5]="_♗_ ";
    tabuleiro[7][2]="_♝_ ";
    tabuleiro[7][5]="_♝_ ";
    
    //rei
    tabuleiro[0][3]="_♔_ ";
    tabuleiro[7][3]="_♚_ ";
    
    //rainha
    tabuleiro[0][4]="_♕_ ";
    tabuleiro[7][4]="_♛_ ";
}

int movimento(int linha, int coluna, std::string direcao, std::string (&tabuleiro)[8][8], bool jogador_branco, bool &erro) {
    std::string peca = tabuleiro[linha][coluna];
    
    int quant, new_linha, new_coluna, movi_linha=0, movi_coluna=0;
    
    std::string peao, torre, cavalo, clero, rei, rainha;

    //trocando a cor das peças de acordo com o turno.
    if (!jogador_branco) {
        // peças pretas.
        peao = "_♙_ ";
        torre = "_♖_ ";
        cavalo = "_♘_ ";
        clero = "_♗_ ";
        rei = "_♔_ ";
        rainha = "_♕_ ";
    } else {
        // peças brancas.
        peao = "_♟_ ";
        torre = "_♜_ ";
        cavalo = "_♞_ ";
        clero = "_♝_ ";
        rei = "_♚_ ";
        rainha = "_♛_ ";
    }
    
    
    
        // escolhendo qual peça foi selecionada e qual o movimento ela vai faser.
    if (peca == peao) { 
        if (direcao == "cima") {    
            if (tabuleiro[linha - 1][coluna] != "___ "){
                std:: cout<<"o peao só pode comer peças na diagonal.";
                erro=true;
                return 0;
            }else{
                new_linha=linha-1;
                new_coluna=coluna;
            }
        }else if(direcao == "esquerda_cima"){
            if (tabuleiro[linha - 1][coluna - 1] == "___ "){
                std:: cout<<"o peao só pode andar na diagonal para comer peças.";
                erro=true;
                return 0;
            }else{
                new_linha=linha-1;
                new_coluna=coluna-1;
            }
        }else if (direcao == "direita_cima"){
            if (tabuleiro[linha - 1][coluna + 1] == "___ "){
                std:: cout<<"o peao só pode andar na diagonal para comer peças.";
            }else{
                new_linha=linha-1;
                new_coluna=coluna+1;
            }
        }else{
            erro=true;
            std::cout<< "direção invalida";
            return 0;
        }
    } else if (peca == torre) { 
       
        std::cout << "Quantidade de blocos que gostaria de andar: ";
        std::cin >> quant;
        
        if (direcao == "cima") {
            new_linha=linha - quant;
            new_coluna=coluna;
            movi_linha=-1;
            
        } else if (direcao == "baixo") {
            new_linha=linha + quant;
            new_coluna=coluna;
            movi_linha=+1;
        } else if (direcao == "esquerda") {
            new_linha=linha;
            new_coluna=coluna - quant;
            movi_coluna=-1;
        } else if (direcao == "direita") {
            new_linha=linha;
            new_coluna=coluna + quant;
            movi_coluna=+1;
        }else{
            erro=true;
            std::cout<< "direção invalida";
            return 0;
        }
        

    } else if (peca == cavalo) { 
    
        if (direcao == "esquerda_cima") {
            new_linha=linha - 1;
            new_coluna=coluna - 2;
        } else if (direcao == "esquerda_baixo") {
            new_linha=linha - 1;
            new_coluna=coluna - 2;
        } else if (direcao == "direita_cima") {
            new_linha=linha - 1;
            new_coluna=coluna + 2;
        } else if (direcao == "direita_baixo") {
            new_linha=linha + 1;
            new_coluna=coluna + 2;
        } else if (direcao == "cima_esquerda") {
            new_linha=linha - 2;
            new_coluna=coluna - 1;
        } else if (direcao == "cima_direita") {
            new_linha=linha - 2;
            new_coluna=coluna + 1;
        } else if (direcao == "baixo_esquerda") {
            new_linha=linha + 2;
            new_coluna=coluna - 1;
        } else if (direcao == "baixo_direita") {
            new_linha=linha + 2;
            new_coluna=coluna + 1;
        }else{
            erro=true;
            std::cout<< "direção invalida";
            return 0;
        }
    } else if (peca == clero) { 
    
        std::cout << "Quantidade de blocos que gostaria de andar: ";
        std::cin >> quant;
    
        if (direcao == "esquerda_cima") {
            new_linha=linha - quant;
            new_coluna=coluna - quant;
            movi_linha=-1;
            movi_coluna=-1;
        } else if (direcao == "direita_cima") {
            new_linha=linha - quant;
            new_coluna=coluna + quant;
            movi_linha=-1;
            movi_coluna=+1;
        } else if (direcao == "esquerda_baixo") {
            new_linha=linha + quant;
            new_coluna= coluna - quant;
            movi_linha=+1;
            movi_coluna=-1;
        } else if (direcao == "direita_baixo") {
            new_linha=linha + quant;
            new_coluna=coluna + quant;
            movi_linha=+1;
            movi_coluna=+1;
        }else{
            erro=true;
            std::cout<< "direção invalida";
            return 0;
        }
    } else if (peca == rei) { 
        if (direcao == "cima") {
            new_linha=linha - 1;
            new_coluna=coluna;
        } else if (direcao == "baixo") {
            new_linha=linha + 1;
            new_coluna=coluna;
        } else if (direcao == "esquerda") {
            new_linha=linha;
            new_coluna=coluna - 1;
        } else if (direcao == "direita") {
            new_linha=linha;
            new_coluna= coluna + 1;
        } else if (direcao == "esquerda_cima") {
            new_linha=linha - 1;
            new_coluna=coluna - 1;
        } else if (direcao == "direita_cima") {
            new_linha=linha - 1;
            new_coluna=coluna + 1;
        } else if (direcao == "esquerda_baixo") {
            new_linha=linha + 1;
            new_coluna=coluna - 1;
        } else if (direcao == "direita_baixo") {
            new_linha=linha + 1;
            new_coluna=coluna + 1;
        }else{
            erro=true;
            std::cout<< "direção invalida";
            return 0;
        }
    } else if (peca == rainha) {
        std::cout << "Quantidade de blocos que gostaria de andar: ";
        std::cin >> quant;
    
        if (direcao == "cima") {
            new_linha=linha - quant;
            new_coluna=coluna;
            movi_linha=-1;
        } else if (direcao == "baixo") {
            new_linha=linha + quant;
            new_coluna=coluna;
            movi_linha=1;
        } else if (direcao == "esquerda") {
            new_linha=linha;
            new_coluna=coluna - quant;
            movi_coluna=-1;
        } else if (direcao == "direita") {
            new_linha=linha;
            new_coluna=coluna + quant;
            movi_coluna=+1;
        } else if (direcao == "esquerda_cima") {
            new_linha=linha - quant;
            new_coluna=coluna - quant;
            movi_linha=-1;
            movi_coluna=-1;
        } else if (direcao == "direita_cima") {
            new_linha=linha - quant;
            new_coluna=coluna + quant;
            movi_linha=-1;
            movi_coluna=1;
        } else if (direcao == "esquerda_baixo") {
            new_linha=linha + quant;
            new_coluna=coluna - quant;
            movi_linha=1;
            movi_coluna=-1;
        } else if (direcao == "direita_baixo") {
            new_linha=linha + quant;
            new_coluna=coluna + quant;
            movi_linha=1;
            movi_coluna=1;
        }else{
            erro=true;
            std::cout<< "direção invalida";
            return 0;
        }
        
    }
    //verificando se a nova posição está dentro do tabuleiro.
    if (new_linha < 0 || new_linha >= 8 || new_coluna < 0 || new_coluna >= 8) {
        std::cout << "Esta posição está fora do tabuleiro." << std::endl;
        erro=true;
        return 0;
        
    //verificando se a posição escolhida já possui uma peça do jogador.
    }else if (tabuleiro[new_linha][new_coluna] == rei || tabuleiro[new_linha][new_coluna] == rainha || tabuleiro[new_linha][new_coluna] == torre || tabuleiro[new_linha][new_coluna] == clero || tabuleiro[new_linha][new_coluna] == cavalo || tabuleiro[new_linha][new_coluna] == peao ){
        std:: cout<< "\nestá posição já está ocupada por uma peça sua.";
        erro=true;
        return 0;
        
    
    //permetindo que APENAS o cavalo pule outras peças do tabuleiro.
    }else if (movi_linha != 0 || movi_coluna != 0){
        //criando variáveis de linha e coluna temporária.
        int temp_linha = linha;
        int temp_coluna = coluna;
        //testando cada posição que será percorrida pela peça.
        for (int i = 0; i < quant-1; i++) {
            temp_linha += movi_linha;
            temp_coluna += movi_coluna;
        
            if (tabuleiro[temp_linha][temp_coluna] != "___ ") {
                std::cout << "Apenas o cavalo pode pular peças no tabuleiro." << std::endl;
                erro=true;                
                return 0;
                
            }
            
        }
        //caso não encontrado nenhum obstáculo ativando o movimento da peça.
        tabuleiro[linha][coluna]="___ ";
        tabuleiro[new_linha][new_coluna]= peca;
        erro=false;
        return 0;
        
    //fazendo o movimento da peça.
    }else{
        tabuleiro[linha][coluna]="___ ";
        tabuleiro[new_linha][new_coluna]= peca;
        erro=false;
        return 0;
    }
}
//função para faser a promoção do peão.
std:: string promocao_peao(bool jogador_branco){
    std:: string rainha, cavalo, torre, clero;
    int Class;
    
    if (jogador_branco){
        torre = "_♜_ ";
        cavalo = "_♞_ ";
        clero = "_♝_ ";
        rainha = "_♛_ ";
    }else{
        torre = "_♖_ ";
        cavalo = "_♘_ ";
        clero = "_♗_ ";
        rainha = "_♕_ ";
    }
    while(true){
        
        std:: cout<<"escolha o número para promover o peão de class.";
        std:: cout<<"\nRainha= 1" <<"\nTorre= 2"<<"\nBispo= 3"<<"\nCavalo= 4"<<"\nnumero: ";
        
        std:: cin>> Class;
        
        if(Class == 1){
            return rainha;
        }else if (Class== 2){
            return torre;
        }else if (Class == 3){
            return clero;
        }else if (Class == 4){
            return cavalo;
        }else{
            std:: cout<< "\nnúmero inválido\n";
            continue;
        }
        
    }
}

//invertendo o tabuleiro na troca de jogador.
void inverter_tabuleiro(std::string (&tabuleiro)[8][8], bool& preto, bool& branco, bool jogador_branco){
    
    //trocando cada peça pela peça na posição inversa.
    for (int i = 0; i < 8 / 2; i++) {
        for (int j = 0; j < 8; j++) {
            std::string temp = tabuleiro[i][j];
            tabuleiro[i][j] = tabuleiro[8 - 1 - i][j];
            tabuleiro[8 - 1 - i][j] = temp;
            //verificando se os reis ainda estão no tabuleiro.
            if (tabuleiro[i][j] == "_♔_ " ||  tabuleiro[8 - 1 - i][j] == "_♔_ "){
                preto = false;
                
            }
            if (tabuleiro[i][j] == "_♚_ " || tabuleiro[8 - 1 - i][j] == "_♚_ "){
                branco = false;
            }
            //verificando se o peao chegou ao outro lado lado do tabuleiro para receber a promoção.
            if (i == 0) {
                if (tabuleiro[8 - 1 - i][j] == "_♙_ " || tabuleiro[8 - 1 - i][j] == "_♟_ ") {
                    tabuleiro[i][j]= promocao_peao(jogador_branco);
                }
                
            }
        }
    }
}
//função para verificar a entrada do jogador.
int entrada(int &linha, int &coluna, std:: string &direcao, std:: string (tabuleiro)[8][8]){
    std:: string teste;
    while(true){
    
        std:: cout<<"\ndigite a posição da peça escolhida e a direçao para andar.";
        //recebendo entradas da linha e coluna e verificando se são números para proceguir.
        std:: cout<< "\nlinha: ";
        std:: cin >> teste;
    
        std:: stringstream aux(teste);
        if (!(aux >> linha)){
            std:: cout<< "\nlinha inválida digite apenas números.\n";
            continue;
        }
        
        std:: cout<< "coluna: ";
        std:: cin>> teste;
        std:: stringstream aux2(teste);
        if (!(aux2 >> coluna)){
            std:: cout<< "\ncoluna inválida digite apenas números.\n";
            continue;
        }
        
         
        //verificando posição.
        if (linha < 1 || linha >= 9 || coluna < 1 || coluna >= 9) {
            std::cout << "Esta posição está fora do tabuleiro." << std::endl;
            continue;
        }
        else if (tabuleiro[linha-1][coluna-1] == "___ "){
            std:: cout<<"está posição não possui peça";
            continue;
        }
        
        std:: cout<<"direção: ";
        std:: cin >> direcao; 
        
        return 0;
    }
}

int main(){
    //criando o tabuleiro e as variáveis.
    int linha, coluna;
    std:: string direcao, tabuleiro[8][8];
    criando_tabuleiro(tabuleiro);
    bool jogador_branco= true, branco= true, preto= true, erro= false;
    
    while (true){
        branco= true;
        preto = true;
    
        //imprimindo o tabuleiro
        for(int i=0; i<8; i++){
            std:: cout<<"\n";
            for (int j=0; j<8; j++){
                std:: cout<<tabuleiro[i][j];
            }
        }
        
        //recebendo posiçao da peça.
        entrada(linha, coluna, direcao, tabuleiro);
        
        //fazendo a movimentação da peça.
        movimento(linha-1, coluna-1, direcao,tabuleiro, jogador_branco, erro);     
        
        if (erro){
            continue;
        }
        inverter_tabuleiro(tabuleiro, preto, branco, jogador_branco);
        
        jogador_branco= !jogador_branco;
        
        if (branco){
            std:: cout<<"VITORIA DAS PEÇAS PRETAS";
            break;
        }else if (preto){
            std:: cout<<"\nVITORIA DAS PEÇAS BRANCAS";
            break;
        }
    }
    return 0;
}
    