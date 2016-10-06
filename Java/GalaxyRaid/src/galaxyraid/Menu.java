/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package galaxyraid;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

/**
 * klasa do rysowania menu
 * @author Michał
 */
public class Menu {
   
    public void tworz(Graphics g)
    {
        Font font = new Font ("Helvetica", Font.BOLD, 48);
        g.setFont(font);
        g.setColor(Color.WHITE);
        g.drawString("GALAXY RAID",(1024-g.getFontMetrics().stringWidth("GALAXY RAID"))/2,100);
        g.setColor(Color.WHITE);
        g.setFont(new Font("Helvetica", Font.PLAIN, 36));
        g.drawString("Sterowanie:",(1024-g.getFontMetrics().stringWidth("Sterowanie:"))/2,500);
        g.drawString("Spacja = Strzał",(1024-g.getFontMetrics().stringWidth("Spacja = Strzał"))/2,540);
        g.drawString("ESC = Pauza",(1024-g.getFontMetrics().stringWidth("ESC = Pauza"))/2,580);
        g.drawString("Strzałki = Ruch",(1024-g.getFontMetrics().stringWidth("Strzałki = Ruch"))/2,620);
    }
}
