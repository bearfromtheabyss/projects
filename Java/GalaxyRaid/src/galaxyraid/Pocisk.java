/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package galaxyraid;

/**
 * Klasa opisujaca pocisk
 * @author Michał
 */
public class Pocisk extends Obiekt{
    private final int wysokoscMapy = 1024;
    private final int predkoscPocisku = 25;
    
    /**
     *
     * @param x - położenie startowe pocisku w X
     * @param y - polożenie startowe pocisku w Y
     */
    public Pocisk(int x, int y) {
        super(x, y);
        
        initPocisk();
    }
    
    private void initPocisk() {
       wczytajObraz("bullet.png");
    }

    /**
     *  usuwa pocisk gdy wyjdzie za plansze i rusza nim
     */
    public void rusz() {
        
        y -= predkoscPocisku;
        
        if (y > wysokoscMapy) {
            widoczny = false;
        }
    }
}
