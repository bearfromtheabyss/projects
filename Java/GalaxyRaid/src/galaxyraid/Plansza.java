/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package galaxyraid;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridBagLayout;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.JPanel;
import javax.swing.Timer;
import java.util.ArrayList;
import javax.swing.ImageIcon;
import javax.swing.JButton;

/**
 * Tutaj wszystko sie dzieje, Plansza!
 *
 * @author Michał
 */
public class Plansza extends JPanel implements ActionListener {
    boolean paused = false;
    private int ileWcisniec = 0;
    private int odswiez = 0;
    private int wynik = 0;
    private Timer czas;
    private Statek statek;
    private Paliwo paliwo;
    private Przeszkoda przeszkoda;
    private StatekWroga wrog;
    private Stan stan;
    private Menu menu;
    private JButton play;
    private Image background;
    private Image backgroundMenu;
    private final int delay = 10;
    private final int statekX = 450;
    private final int statekY = 600;
    private final ArrayList<Paliwo> kanister = new ArrayList<>();
    private final ArrayList<StatekWroga> wrogowie = new ArrayList<>();
    private final ArrayList<Przeszkoda> przeszkody = new ArrayList<>();
    boolean running = true;

    /**
     * initPlansza - metoda w konstruktorze aby zapobiec bledom, dziwnym trafem Java nie lubi jak sie jej pisze w konstruktorach rzeczy
     * To co jest w initPlansza wydaje się być oczywiste
     */
    public Plansza() {
        initPlansza();
    }

    private void initPlansza() {
        setLayout(new GridBagLayout());
        addKeyListener(new Klawisze());
        setFocusable(true);
        setBackground(Color.BLUE);
        stan = Stan.MENU;
        play = new JButton("GRAJ!");
        play.setPreferredSize(new Dimension(200, 100));
        play.setForeground(Color.WHITE);
        play.setBackground(Color.BLACK);
        play.setFont(new Font("Helvetica", Font.BOLD, 48));
        statek = new Statek(statekX, statekY);
        menu = new Menu();
        ImageIcon ikonka0 = new ImageIcon(this.getClass().getResource("img/background4.jpg"));
        background = ikonka0.getImage();
        ImageIcon ikonka1 = new ImageIcon(this.getClass().getResource("img/background3.jpg"));
        backgroundMenu = ikonka1.getImage();
        setMinimumSize(new Dimension(WIDTH, HEIGHT));
        czas = new Timer(delay, this);
        czas.start();
        if (stan == Stan.MENU) {
            add(play);
        }
        initRzeczy();
    }
    //Inicjalizuje różne obiekty na mapie, dodaje po jednym do kazdej z list, pozniej listy sa odsswiezane
    private void initRzeczy() {
        if (stan == Stan.GAME) {
            wrog = new StatekWroga(0, -600);
            wrogowie.add(wrog);
            paliwo = new Paliwo(0, 0);
            kanister.add(paliwo);
            przeszkoda = new Przeszkoda(0, -600);
            przeszkody.add(przeszkoda);
        }
    }
    // rysuje rzeczy
    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (stan == Stan.MENU) {
            g.drawImage(backgroundMenu, 0, 0, null);
            menu.tworz(g);
            add(play);
            play.addActionListener(this);
        } else {
            Graphics2D g2 = (Graphics2D) g;
            g2.drawImage(background, 0, 0, null);
            ArrayList pociski = statek.getPociski();

            for (Object p1 : pociski) {
                Pocisk p = (Pocisk) p1;
                g2.drawImage(p.getObraz(), p.getX(), p.getY(), this);
            }
            g2.drawImage(statek.getObraz(), statek.getX(), statek.getY(), this);

            for (Paliwo paliwo : kanister) {
                g2.drawImage(paliwo.getObraz(), paliwo.getX(), paliwo.getY(), paliwo.getSzerokosc(), paliwo.getWysokosc(), this);
            }
            for (Przeszkoda p : przeszkody) {
                g2.drawImage(p.getObraz(), p.getX(), p.getY(), this);
            }
            for (StatekWroga wrog : wrogowie) {
                g2.drawImage(wrog.getObraz(), wrog.getX(), wrog.getY(), this);
            }
            g2.setColor(Color.YELLOW);
            g2.drawRect(800, 20, statek.getPaliwo(), 30);
            g2.fillRect(800, 20, statek.getPaliwo(), 30);

            if (paused) {
                 g.drawString("PAUSE",(1024-g.getFontMetrics().stringWidth("PAUSE"))/2,200);
                g.drawString("Naciśnij ESC, aby kontynuować",(1024-g.getFontMetrics().stringWidth("Naciśnij ESC, aby kontynuować"))/2,300);
        }
            drawStrings(g2);
            if (!running) {
                rysujGameOver(g, gameOver());
                g.drawString("Naciśnij SPACJE aby zresetować grę.", getWidth() / 4, getHeight() / 2);
            }
            Toolkit.getDefaultToolkit().sync();
        }
    }
    
    

    private void rysujGameOver(Graphics g, String msg) {
        Font small = new Font("Helvetica", Font.BOLD, 24);
        FontMetrics fm = getFontMetrics(small);
        g.setColor(Color.white);
        g.setFont(small);
        g.drawString("GAME OVER", getWidth() / 4, (getHeight() / 2) - 50);
        g.drawString(msg, (1024 - fm.stringWidth(msg)) / 2, 800 / 2);
    }

    /**
     * drawStrings - rysuj napisy na planszy, wynik i paliwo
     * @param g - obiekt Graphics2D
     */
    public void drawStrings(Graphics2D g) {
        String wynikString;
        String paliwoString;
        wynikString = "Wynik: " + wynik;
        g.setColor(Color.WHITE);
        g.setFont(new Font("Helvetica", Font.PLAIN, 48));
        g.drawString(wynikString, 150, 48);
        paliwoString = "Paliwo: ";
        g.drawString(paliwoString, 650, 48);
    }

    /**
     *  
     * @return msg - zwraca String z komunikatem zdarzenia.
     */
    public String gameOver() {
        String msg = "";
        if (statek.getPaliwo() <= 0) {
            running = false;
            msg = "Zabrakło ci paliwa!";
        }
        if (wynik == 100000) {
            running = false;
            msg = "Gra ukończona, jesteś mistrzem River Raid, oto Twój medal Mistrza River Raid";
        }
        return msg;
    }
    //RESTART GRY.... -..-
    private void restart() {
        running = true;
        czas.start();
        przeszkody.clear();
        wrogowie.clear();
        kanister.clear();
        statek.setPos(450, 600);
        statek.setPaliwo(150);
        wynik = 0;
    }
    /*
    * Tutaj dzieje się wszystko, serce gry. Odswiezany event obraca ta petla az do konca jej dni.
    */
    @Override
    public void actionPerformed(ActionEvent e) {
        if (play.getModel().isArmed()) {
            stan = Stan.GAME;
            restart();
            removeAll(); 
        }
        
        graDziala();
        updatePociski();
        updateStatek();
        updatePaliwo();
        updatePrzeszkody();
        updateWrog();
        kolizja();
        gameOver();
        if (odswiez % 150 == 0) {
            updateArrayLists();
        }
        repaint();
        odswiez++;
        
    }
    // funkcje odpowiedzialne za poruszanie lub usuwanie obiektow. Aktualizuja ich pozycje na mapie, a gdy wyleca poza granice okna lub zostana zestrzelone
    // to przestana byc widoczne i zninka
    private void updatePociski() {

        ArrayList ms = statek.getPociski();

        for (int i = 0; i < ms.size(); i++) {

            Pocisk m = (Pocisk) ms.get(i);

            if (m.getWidocznosc()) {
                m.rusz();
            } else {
                ms.remove(i);
            }
        }
    }
    // Dodawanie nowych obiektow aby zachowac ciaglosc gry, zeby ciagle bylo w co strzelac, co zbierac
    private void updateArrayLists() {
        if (stan == Stan.GAME) {
            StatekWroga e = new StatekWroga(0, -600);
            wrogowie.add(e);
            Paliwo f = new Paliwo(0, -500);
            kanister.add(f);
            Przeszkoda o = new Przeszkoda(0, -600);
            przeszkody.add(o);
        }
    }
    //patrz: updatePociski
    private void updateWrog() {

        for (int i = 0; i < wrogowie.size(); i++) {

            StatekWroga s = wrogowie.get(i);

            if (s.getWidocznosc()) {

                s.rusz();
            } else {
                wrogowie.remove(i);
            }
        }
    }
    //patrz: updatePociski
    private void updatePaliwo() {
        for (int i = 0; i < kanister.size(); i++) {

            Paliwo p = kanister.get(i);

            if (p.getWidocznosc()) {
                p.rusz();
            } else {
                kanister.remove(i);
            }
        }
    }
    //patrz: updatePociski
    private void updatePrzeszkody() {
        for (int i = 0; i < przeszkody.size(); i++) {

            Przeszkoda p = przeszkody.get(i);

            if (p.getWidocznosc()) {
                p.rusz();
            } else {
                przeszkody.remove(i);
            }
        }
    }
    //patrz: updatePociski
    private void updateStatek() {
        statek.rusz();
    }

    /**
     * gdy running zmieni swoj stan na false to zatrzymana bedzie gra dzieki temu
     */
    public void graDziala() {
        if (running == false) {
            czas.stop();
        }
    }
    // sprawdzanie kolizji z innymi elementami.
    private void kolizja() {
        Rectangle squareStatek = statek.getGranice();

        for (StatekWroga wrog : wrogowie) {
            Rectangle squareWrog = wrog.getGranice();

            if (squareStatek.intersects(squareWrog)) {
                statek.setWidocznosc(false);
                wrog.setWidocznosc(false);
                running = false;
            }
        }

        ArrayList<Pocisk> pociski = statek.getPociski();

        for (Pocisk pocisk : pociski) {

            Rectangle squarePocisk = pocisk.getGranice();

            for (StatekWroga wrog : wrogowie) {

                Rectangle squareWrog = wrog.getGranice();

                if (squarePocisk.intersects(squareWrog)) {
                    pocisk.setWidocznosc(false);
                    wrog.setWidocznosc(false);
                    wrog.widoczny = false;
                    wynik += 100;
                }
            }
        }

        for (Paliwo paliwo : kanister) {
            Rectangle r4 = paliwo.getGranice();
            if (squareStatek.intersects(r4)) {
                statek.setPaliwo(50);
                paliwo.setWidocznosc(false);
            }
        }
        for (Przeszkoda p : przeszkody) {
            Rectangle squarePaliwo = p.getGranice();
            for (Pocisk pocisk : pociski) {
                Rectangle squarePocisk = pocisk.getGranice();
                if (squarePocisk.intersects(squarePaliwo)) {
                    pocisk.setWidocznosc(false);
                }
            }
            if (squarePaliwo.intersects(squareStatek)) {
                running = false;
            }
        }
        if (statek.getX() > getWidth() || statek.getY() > getHeight() || statek.getX() < 0 || statek.getY() < 0) { // jeżeli wyleci poza okno to sie rozbije
            running = false;
        }
    }
    /*
    * Klasa która odpowiada za wyłapywanie eventów klawiszy, przekazywane do klasy Statek aby móc nim poruszyć
    */
    private class Klawisze extends KeyAdapter {

        @Override
        public void keyReleased(KeyEvent e) {
            statek.keyReleased(e);

        }

        @Override
        public void keyPressed(KeyEvent e) {
            statek.keyPressed(e);
            if (e.getKeyCode() == KeyEvent.VK_ESCAPE) { // pauza gry
                czas.stop();
                paused = true;
                ileWcisniec++;
            }
            if (ileWcisniec == 2) {
                czas.start();
                paused = false;
                ileWcisniec = 0;
            }
            if (e.getKeyCode() == KeyEvent.VK_SPACE && !running) {
                restart();
            }
        }
    }
}
