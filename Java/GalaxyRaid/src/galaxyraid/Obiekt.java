/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package galaxyraid;

import java.awt.Image;
import java.awt.Rectangle;
import java.awt.Toolkit;

/**
 * Klasa pewnego obiektu, nadrzedna wobec obiektow na mapie
 * @author Michał
 */
public class Obiekt {
    protected int x;
    protected int y;
    protected int szerokosc;
    protected int wysokosc;
    protected boolean widoczny;
    protected Image image;
    public Obiekt(int x, int y) {
        this.x = x;
        this.y = y;
        widoczny = true;
    }

    protected void wczytajObraz(String imageName)
    {
      image = Toolkit.getDefaultToolkit().createImage(this.getClass().getResource("/img/"+imageName));
    }
    
    public Image getObraz() {
        szerokosc = image.getWidth(null);
        wysokosc = image.getHeight(null);
        return image;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public boolean getWidocznosc() {
        return widoczny;
    }
    public int getSzerokosc()
    {
        return szerokosc;
    }
     public int getWysokosc()
    {
        return wysokosc;
    }
    public void setWidocznosc(Boolean wid) {
        widoczny = wid;
    }
    public Rectangle getGranice() 
    {
        return new Rectangle(x, y, szerokosc-5, wysokosc-5);
    }
}
