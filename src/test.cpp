#include "test.hpp"


/** Fonction qui effectue un test sur plateau_to_string
 * @param got la chaine de caractere renvoyee par plateau_to_string
 * @param expected la chaine de caractere que l'on attend
 **/
void assert_string_equal(string got, string expected) {

  if (got != expected) {
    cout << "got:" << endl << "`" << endl << got << "`" << endl << "but expected:" << endl << "`" << endl << expected << "`" << endl;
  }

  assert (got == expected);

}


/** Lance une serie de test sur la fonction plateau_to_string **/
void test_plateau_to_string() {

  string got = plateau_to_string ({{2,4,8,16}, {32,64,128,256}, {512,1024,2048,4096}, {0,0,0,0}});
  string expected = "*************************\n*  2  *  4  *  8  * 16  *\n*************************\n* 32  * 64  * 128 * 256 *\n*************************\n* 512 *1024 *2048 *4096 *\n*************************\n*     *     *     *     *\n*************************\n";

  assert_string_equal(got, expected);

  string got2 = plateau_to_string ({{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}});
  string expected2 = "*************************\n*     *     *     *     *\n*************************\n*     *     *     *     *\n*************************\n*     *     *     *     *\n*************************\n*     *     *     *     *\n*************************\n";

  assert_string_equal(got2, expected2);

  string got3 = plateau_to_string ({{2,4,8,16}, {32,64,128,256}, {512,1024,2048,4096}, {8192,4096,2048,1024}});
  string expected3 = "*************************\n*  2  *  4  *  8  * 16  *\n*************************\n* 32  * 64  * 128 * 256 *\n*************************\n* 512 *1024 *2048 *4096 *\n*************************\n*8192 *4096 *2048 *1024 *\n*************************\n";

  assert_string_equal(got3, expected3);

}


/** Teste la fonction genere_nombre **/
void test_genere_nombre() {
  int nombre = genere_nombre();
  assert(nombre == 2 or nombre == 4);
}


/** Teste la fonction init_plateau **/
void test_init_plateau() {
  Plateau tab = init_plateau(2);
  int nb_deux = 0;
  for(vector<int> ligne : tab) {
    for(int nombre : ligne) {
      if(nombre == 2) {
        nb_deux++;
      } else {
        assert(nombre == 0);
      }
    }
  }
  assert(nb_deux == 1);
}


/** Teste la fonction ajoute_nombre_plateau **/
void test_ajoute_nombre_plateau() {
  Plateau tab = {{0,2,0,2}, {2,0,2,0}, {2,2,0,0}, {0,0,2,2}};
  int nombre_deux_ou_quatre = 0;
  tab = ajoute_nombre_plateau(tab, genere_nombre());
  for(vector<int> ligne : tab) {
    for(int nombre : ligne) {
      if(nombre == 2 or nombre == 4) {
        nombre_deux_ou_quatre++;
      }
    }
  }
  assert(nombre_deux_ou_quatre == 9);
}


/** Fonction qui lance le test de toutes les fonctions **/
void test_all() {
  test_plateau_to_string();
  test_genere_nombre();
  test_init_plateau();
  test_ajoute_nombre_plateau();
}
