#include "gtest-1.8.1/gtest.h"
#include "../src/Conjunto.h"


/**
 * Test simple básico
 */
TEST(conjunto_test, conjunto_vacio) {
    Conjunto<int> c;
    EXPECT_EQ(c.cardinal(), 0);
}


TEST(conjunto_test, test_insertar_un_valor) {
    Conjunto<int> c;
    c.insertar(5);
    EXPECT_EQ(c.cardinal(), 1);
}


TEST(conjunto_test, test_insertar_cinco_valores) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    EXPECT_EQ(c.cardinal(), 5);
}

TEST(conjunto_test, test_pertenece) {
  Conjunto<int> c;
  
  for (int i = 0; i < 5; i++) {
    EXPECT_FALSE(c.pertenece(i));
  }

  // Agrego el 3
  c.insertar(3);
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(c.pertenece(i), i == 3);
  }

  // Agrego el 3
  c.insertar(5);
  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(c.pertenece(i), i == 3);
  }
  EXPECT_TRUE(c.pertenece(5));

}

TEST(conjunto_test, test_insertar_remover_un_valor) {
    Conjunto<int> c;
    c.insertar(5);
    c.remover(5);
    EXPECT_EQ(c.cardinal(), 0);
    c.insertar(5);
    EXPECT_EQ(c.cardinal(), 1);
}

TEST(conjunto_test, test_minimo) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    EXPECT_EQ(c.minimo(), 4);
}

TEST(conjunto_test, test_maximo) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    EXPECT_EQ(c.maximo(), 8);
}

TEST(conjunto_test, mariantest1) {
    Conjunto<int> c;
    c.insertar(1);
    c.insertar(2);
    c.insertar(3);
    c.remover(1);
    EXPECT_EQ(c.cardinal(), 2);
    EXPECT_FALSE(c.pertenece(1));
    EXPECT_TRUE(c.pertenece(2));
    EXPECT_TRUE(c.pertenece(3));


    c.remover(2);
    c.insertar(3);
    c.insertar(2);
    c.insertar(1);
    c.remover(3);
    EXPECT_EQ(c.cardinal(), 2);
    EXPECT_FALSE(c.pertenece(3));
    EXPECT_TRUE(c.pertenece(2));
    EXPECT_TRUE(c.pertenece(1));

    c.insertar(3);
    c.remover(2);
    EXPECT_EQ(c.cardinal(), 2);
    EXPECT_FALSE(c.pertenece(2));
    EXPECT_TRUE(c.pertenece(1));
    EXPECT_TRUE(c.pertenece(3));

    c.remover(1);
    c.remover(3);
    EXPECT_EQ(c.cardinal(), 0);
    EXPECT_FALSE(c.pertenece(1));
    EXPECT_FALSE(c.pertenece(2));
    EXPECT_FALSE(c.pertenece(3));
}

TEST(conjunto_test, mariantest2) {
    Conjunto<int> c;
    c.insertar(0);
    c.insertar(1);
    c.insertar(2);
    c.insertar(3);
    c.remover(1);
    EXPECT_EQ(c.cardinal(), 3);
    EXPECT_FALSE(c.pertenece(1));
    EXPECT_TRUE(c.pertenece(0));
    EXPECT_TRUE(c.pertenece(2));
    EXPECT_TRUE(c.pertenece(3));


    c.remover(2);
    c.insertar(3);
    c.insertar(2);
    c.insertar(1);
    c.remover(3);
    EXPECT_EQ(c.cardinal(), 3);
    EXPECT_FALSE(c.pertenece(3));
    EXPECT_TRUE(c.pertenece(0));
    EXPECT_TRUE(c.pertenece(2));
    EXPECT_TRUE(c.pertenece(1));

    c.insertar(3);
    c.remover(2);
    EXPECT_EQ(c.cardinal(), 3);
    EXPECT_FALSE(c.pertenece(2));
    EXPECT_TRUE(c.pertenece(0));
    EXPECT_TRUE(c.pertenece(1));
    EXPECT_TRUE(c.pertenece(3));

    c.remover(1);
    c.remover(3);
    EXPECT_EQ(c.cardinal(), 1);
    EXPECT_FALSE(c.pertenece(1));
    EXPECT_FALSE(c.pertenece(2));
    EXPECT_FALSE(c.pertenece(3));
    EXPECT_TRUE(c.pertenece(0));
}

TEST(conjunto_test, mariantest3) {
    Conjunto<int> c;
    c.insertar(99);
    c.insertar(1);
    c.insertar(2);
    c.insertar(3);
    c.remover(1);
    EXPECT_EQ(c.cardinal(), 3);
    EXPECT_FALSE(c.pertenece(1));
    EXPECT_TRUE(c.pertenece(99));
    EXPECT_TRUE(c.pertenece(2));
    EXPECT_TRUE(c.pertenece(3));


    c.remover(2);
    c.insertar(3);
    c.insertar(2);
    c.insertar(1);
    c.remover(3);
    EXPECT_EQ(c.cardinal(), 3);
    EXPECT_FALSE(c.pertenece(3));
    EXPECT_TRUE(c.pertenece(99));
    EXPECT_TRUE(c.pertenece(2));
    EXPECT_TRUE(c.pertenece(1));

    c.insertar(3);
    c.remover(2);
    EXPECT_EQ(c.cardinal(), 3);
    EXPECT_FALSE(c.pertenece(2));
    EXPECT_TRUE(c.pertenece(99));
    EXPECT_TRUE(c.pertenece(1));
    EXPECT_TRUE(c.pertenece(3));

    c.remover(1);
    c.remover(3);
    EXPECT_EQ(c.cardinal(), 1);
    EXPECT_FALSE(c.pertenece(1));
    EXPECT_FALSE(c.pertenece(2));
    EXPECT_FALSE(c.pertenece(3));
    EXPECT_TRUE(c.pertenece(99));
}

TEST(conjunto_test, test_remover_caso_un_hijo) {
    Conjunto<int> c;
    c.insertar(99);
    c.insertar(4);
    c.insertar(5);
    c.insertar(6);
    c.insertar(7);
    c.remover(6);
    EXPECT_EQ(c.cardinal(), 4);
    EXPECT_FALSE(c.pertenece(6));
}

TEST(conjunto_test, test_remover_caso_dos_hijos_simple) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    c.remover(7);
    EXPECT_EQ(c.cardinal(), 4);
    EXPECT_FALSE(c.pertenece(7));
}

TEST(conjunto_test, test_remover_caso_dos_hijos_doble) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(20);
    c.insertar(15);
    c.insertar(12);
    c.insertar(16);
    c.insertar(24);
    c.insertar(22);
    c.insertar(25);
    c.remover(20);
    EXPECT_EQ(c.cardinal(), 8);
    EXPECT_FALSE(c.pertenece(20));
}

TEST(conjunto_test, test_siguiente_inorder) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(20);
    c.insertar(15);
    c.insertar(12);
    c.insertar(16);
    c.insertar(24);
    c.insertar(22);
    c.insertar(25);

    EXPECT_EQ(c.siguiente(20), 22);
    EXPECT_EQ(c.siguiente(4), 5);
    EXPECT_EQ(c.siguiente(15), 16);
}

const int NCLAVES = 10000; // no te asustes si se demora

int clave(int i) {
	return NCLAVES * ((i * i - 100 * i) % NCLAVES) + i;
}

TEST(conjunto_test, test_stress) {
    Conjunto<int> c;

    // Chequeo que no se repitan
    for (int i = 0; i < NCLAVES; i++) {
        for (int j = 0; j < NCLAVES; j++) {
            if(i != j) ASSERT_FALSE(clave(i) == clave(j));
        }
    }

    // Insertar
    for (int i = 0; i < NCLAVES; i++) {
	    int k = clave(i);
	    ASSERT_EQ(c.cardinal(), i);
	    ASSERT_FALSE(c.pertenece(k));
	    c.insertar(k);
	    ASSERT_TRUE(c.pertenece(k));
    }
    ASSERT_EQ(c.cardinal(), NCLAVES);

    // Insertar de nuevo
    for (int i = 0; i < NCLAVES; i++) {
	    int k = clave(i);
	    ASSERT_TRUE(c.pertenece(k));
	    c.insertar(k);
	    ASSERT_TRUE(c.pertenece(k));
	    ASSERT_EQ(c.cardinal(), NCLAVES);
    }

    // Chequear que estén todos
    for (int i = 0; i < NCLAVES; i++) {
        ASSERT_TRUE(c.pertenece(clave(i)));
    }
    ASSERT_EQ(c.cardinal(), NCLAVES);


    // Eliminar los valores para i par
    for (int i = 0; i < NCLAVES; i++) {
	    int k = clave(i);
	    ASSERT_TRUE(c.pertenece(k));
	    if (i % 2 == 0) {
	    	c.remover(k);
	    	ASSERT_FALSE(c.pertenece(k));
	    }
    }
    ASSERT_EQ(c.cardinal(), NCLAVES / 2); //<==

    // Eliminar los valores para i impar
    for (int i = 0; i < NCLAVES; i++) {
	    int k = clave(i);
	    if (i % 2 == 0) {
	    	ASSERT_FALSE(c.pertenece(k));
	    } else {
	    	ASSERT_TRUE(c.pertenece(k));
	    	c.remover(k);
	    	ASSERT_FALSE(c.pertenece(k));
	    }
    }
    ASSERT_EQ(c.cardinal(), 0);

    // Verificar que no haya valores
    for (int i = 0; i < NCLAVES; i++) {
	    int k = clave(i);
	    ASSERT_FALSE(c.pertenece(k));
    }//*/
}
