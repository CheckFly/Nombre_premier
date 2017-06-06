#include <iostream>
#include <vector>


using namespace std;

int main()
{
    using std::vector;
    vector<int> t(519000);

    unsigned int    nbElement=1730,
                    ligne=1,
                    cpt=0,
                    nbPremier=300;

    unsigned int tbl[nbPremier][nbElement];
    printf("initialisation\n");

    for(unsigned int i=0;i<nbPremier;i++){
        for(unsigned int j=0;j<nbElement;j++){
            tbl[i][j]=0;
        }
    }
    printf("incrément des nombres\n");
    for(unsigned int i=1;i<nbElement+1;i++){
        tbl[0][i-1]=i;
    }

    printf("recher nb Premier\n");

    for(unsigned int col=1;col<nbElement;col++){
        for(unsigned int li=1;li<ligne;li++){
            cpt+=tbl[li][col];
            if(cpt!=0){
                //printf("sortie boucle ligne %i col %i\n",li,col);
                break;
            }
        }
        if(cpt==0){
            // insertion du nom de la ligne
            //printf("insertion nb Premier %i\n",ligne);
            tbl[ligne][0]=tbl[0][col];
            for(unsigned int i=col;i<nbElement;i=i+tbl[ligne][0]){
                tbl[ligne][i]=1;
            }
            ligne++;
        }
        cpt=0;
    }



 /*   for(int i=0;i<nbPremier;i++){
        for(int j=0;j<nbElement;j++){
            printf("%i ",tbl[i][j]);
        }
        printf("\n");
    }
*/
    printf("Affichage nb Premier\n");
    for(unsigned int i=0;i<nbPremier;i++){
        printf("index : %i:%i ",i,tbl[i][0]);
        printf("\n");
    }



    return 0;
}
