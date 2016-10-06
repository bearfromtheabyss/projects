/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package galaxyraid;

import java.util.Random;

/**
 * Klasa opisujaca przeszkodę
 * @author Michał
 */
public class Przeszkoda extends Obiekt{

    /**
     *
     * @param x - polozenie powiekszone o losowa wartosc taka jak szerokosc mapy
     * @param y - polozenie powiekszone o losowa wartosc
     */
    public Przeszkoda(int x, int y) {
        super(x+randomPosX(), y+randomPosY());
        initPrzeszkoda();
    }
    
    private void initPrzeszkoda() {
      wczytajObraz("Meteor.gif");
    }

    /**
     * 
     * @return - zwraca losowa wartosc x
     */
    public static int randomPosX(){
        Random rand = new Random();
        int value = rand.nextInt(768);
        return value;
    }
    
    /**
     *
     * @return - zwraca losowa wartosc y
     */
    public static int randomPosY(){
        Random rand = new Random();
        int value = rand.nextInt(3);
        return value;
    }
   
    
    public void rusz() {
      y++;
    }
}
