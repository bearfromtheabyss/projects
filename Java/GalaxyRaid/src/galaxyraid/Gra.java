/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package galaxyraid;

import java.awt.Dimension;
import java.awt.EventQueue;
import javax.swing.JFrame;

/**
 *
 * @author Michał
 */
public class Gra extends JFrame {

    private final static int SZEROKOSC =1024;
    private final static int WYSOKOSC = 768;


    Gra() {
        initGra();
    }

    private void initGra() {
        add(new Plansza());
        setTitle("GALAXY RAID");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(SZEROKOSC, WYSOKOSC);
        setPreferredSize(new Dimension(SZEROKOSC, WYSOKOSC));
        setLocationRelativeTo(null);
        pack();
        setVisible(true);
        setResizable(false);
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            Gra gra = new Gra();
            gra.setVisible(true);
        });

    }

}
