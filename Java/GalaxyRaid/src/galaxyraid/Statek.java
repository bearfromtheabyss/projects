/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package galaxyraid;

import java.awt.event.KeyEvent;
import java.util.ArrayList;


/**
 * Klasa opisujaca Statek
 * @author Michał
 */
public class Statek extends Obiekt {

    private int px, py;
    private final int predkosc = 8;
    private int odswiez;
    private ArrayList pociski;
    private int paliwo = 150;

    /**
     *
     * @param x - pozycja na mapie X
     * @param y - pozycja na mapie Y
     *
     */
    public Statek(int x, int y) {
        super(x, y);
        initStatek();
        odswiez = 0;
    }

    private void initStatek() {
        pociski = new ArrayList();
        wczytajObraz("small.png");
    }

    public void rusz() {
        x += px;
        y += py;
    }

    /**
     * Przesuwa statek
     * @param x - ustal pozycje x
     * @param y - ustal pozycje y
     */
    public void setPos(int x, int y) {
       this.x = x;
       this.y = y;
    }

    /**
     *  
     * @return - Zwraca pomniejszona ilosc paliwa, aby stworzyc efekt podarzania ku słońcu
     */
    public int getPaliwo() {
        if (odswiez % 100 == 1) {
            paliwo -= 2;
        }
        odswiez++;
        return paliwo;
    }

    /**
     *  Ilosc paliwa do testow JUnit
     * @return - zwraca aktualna ilosc paliwa
     */
    public int testGetPaliwo()
    {
        return paliwo;
    }

    /**
     * 
     * @param paliwo - Dodaje ilosc paliwa po najechaniu na beczke z paliwem
     */
    public void setPaliwo(int paliwo) {
        this.paliwo += paliwo;
        if (this.paliwo > 150) {
            this.paliwo = 150;
        }
    }

    /**
     *  Wydarzenia zwiazane z naciskaniem strzalek (wychwytywanie eventow po nacisnieciuc strzalek)
     * @param e - event
     */
    public void keyPressed(KeyEvent e) {

        int key = e.getKeyCode();

        if (key == KeyEvent.VK_LEFT) {
            px = -predkosc;
            paliwo--;
        }

        if (key == KeyEvent.VK_RIGHT) {
            px = predkosc;
            paliwo--;
        }

        if (key == KeyEvent.VK_UP) {
            py = -predkosc;
            paliwo--;
        }

        if (key == KeyEvent.VK_DOWN) {
            py = predkosc;
            paliwo--;
        }
        if (key == KeyEvent.VK_SPACE) {
            strzel();
        }

    }

    /**
     *
     * @param e - Obiekt przechwytujący wciśnięcia klaawiszy
     */
    public void keyReleased(KeyEvent e) {

        int key = e.getKeyCode();

        if (key == KeyEvent.VK_LEFT) {
            px = 0;
        }

        if (key == KeyEvent.VK_RIGHT) {
            px = 0;
        }

        if (key == KeyEvent.VK_UP) {
            py = 0;
        }

        if (key == KeyEvent.VK_DOWN) {
            py = 0;
        }
    }

    /**
     *  
     * @return - Zwraca liste z pociskami w statku
     */
    public ArrayList getPociski() {
        return pociski;
    }

    /**
     * strzela i dodaj nowy pocisk do listy przez co nigdy ich nie zabraknie
     */
    public void strzel() {
        pociski.add(new Pocisk(x+27, y));
    }
}
