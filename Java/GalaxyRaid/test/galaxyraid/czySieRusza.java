/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package galaxyraid;

import org.junit.Test;
import static org.junit.Assert.fail;

/**
 *
 * @author Michał
 */
public class czySieRusza {
    Statek statek = new Statek(100,100);
    int roznica;
    int ruch;
    public czySieRusza() {
        
    }
    
    @Test
    public void czyRuszyl()
    {
       roznica = statek.getX();
       statek.setPos(101,101);
       ruch = statek.getX();
       if(ruch - roznica != 1){
           fail("Statek nie ruszyl sie");
       }
       else
           System.out.print("Ruszyl");
    }
}
