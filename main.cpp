#include <iostream>
#include <vector>


using namespace std;

int main()
{
    using std::vector;

    unsigned int    nbElement=100000,
                    ligne=1,
                    cpt=0;


    vector<vector<unsigned int>> v;

    v.push_back(vector<unsigned int>(nbElement,0));

//    unsigned int tbl[nbPremier][nbElement];
//    printf("initialisation\n");
//
//    for(unsigned int i=0;i<nbPremier;i++){
//        for(unsigned int j=0;j<nbElement;j++){
//            tbl[i][j]=0;
//        }
//    }

    printf("incrément des nombres\n");
    for(unsigned int i=1;i<nbElement+1;i++){
        v[0][i-1]=i;
    }

    printf("recher nb Premier\n");

    for(unsigned int col=1;col<nbElement;col++){
        for(unsigned int li=1;li<ligne;li++){
            cpt+=v[li][col];
            if(cpt!=0){
                //printf("sortie boucle ligne %i col %i\n",li,col);
                break;
            }
        }
        if(cpt==0){
            // insertion du nom de la ligne
            //printf("insertion nb Premier %i\n",ligne);
            v.push_back(vector<unsigned int>(nbElement,0));
            v[ligne][0]=v[0][col];
            for(unsigned int i=col;i<nbElement;i=i+v[ligne][0]){
                v[ligne][i]=1;
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
    for(unsigned int i=0;i<v.size() ;i++){
        printf("index : %i:%i ",i,v[i][0]);
        printf("\n");
    }



    return 0;
}
