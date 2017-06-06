#include <iostream>
#include <vector>


using namespace std;

int main()
{
    using std::vector;

    unsigned int    nbElement=0,
                    ligne=2,
                    cpt=0;

    printf("insert le nombre element :");
    scanf("%i", &nbElement);
    printf("\n");

    vector<vector<bool>> v;
    vector<unsigned int> tblNbElement(nbElement);
    vector<unsigned int> tblNbPremier;

    v.push_back(vector<bool>(nbElement,false));
    v.push_back(vector<bool>(nbElement,false));
    tblNbPremier.push_back(1);

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
        tblNbElement[i-1]=i;
    }

    printf("recher nb Premier\n");
    unsigned int col;
    unsigned int li;
    unsigned int i;

    for(col=1;col<nbElement;col++){
        //printf("1 cpt %i  col %i li %i ligne %i val %i \n",cpt,col,li,ligne,(int)v[li][col]);
        for(li=1;li<ligne;li++){
            //printf("1 cpt %i  col %i li %i ligne %i val %i \n",cpt,col,li,ligne,(int)v[li][col]);
            cpt+=v[li][col];
            //printf("1 cpt %i  col %i li %i ligne %i val %i \n",cpt,col,li,ligne,(int)v[li][col]);
            if(cpt!=0){
                //printf("sortie boucle ligne %i col %i\n",li,col);
                break;
            }
        }
        if(cpt==0){
            // insertion du nom de la ligne
            //printf("insertion nb Premier %i\n",ligne);
            v.push_back(vector<bool>(nbElement,false));
            unsigned int val =tblNbElement[col];
            tblNbPremier.push_back(val);
            //printf("taille tblNB %i val %i val %i\n", (int)tblNbPremier.size(), tblNbPremier[ligne], tblNbElement[col]);
            for(i=col;i<nbElement;i=i+tblNbElement[col]){
                v[ligne][i]=true;
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
//    printf("Affichage nb Premier\n");
//    for(unsigned int i=0;i<v.size() ;i++){
//        printf("index : %i:%i ",i,v[i][0]);
//        printf("\n");
//    }
    unsigned int total=tblNbPremier.size()-1;
    printf("nombre de nb premier %i %i",total, tblNbPremier[total]);

    return 0;
}
