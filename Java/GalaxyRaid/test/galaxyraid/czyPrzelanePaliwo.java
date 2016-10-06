/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package galaxyraid;

import static org.junit.Assert.fail;
import org.junit.Test;

/**
 *
 * @author Michał
 */
public class czyPrzelanePaliwo {

    Statek statek = new Statek(0, 0);

    public czyPrzelanePaliwo() {
    }

    @Test
    public void przelej() {
        int paliwoObecnie;
        int dolewanie = 1000;
        int paliwoPoDolaniu;
        paliwoObecnie = statek.testGetPaliwo();
        statek.setPaliwo(dolewanie);
        paliwoPoDolaniu = statek.testGetPaliwo();
        if(paliwoPoDolaniu - paliwoObecnie != 0 ){
            fail("Przelano paliwa, katastrofa nuklearna!");
        }
    }

}
