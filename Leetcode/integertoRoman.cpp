class Solution {
public:
    string intToRoman(int num) {
        string s ;
        
        int z,i=0;
        while(num>0){
            if(num>=1000){
                for(z=0;z<num/1000;z++){
                    s+='M';
                }
                num=num%1000;
                
               
            }
            else if(num>=500){
                if(num>=900){
                    num=num%900;
                    s+='C';
                    s+='M';
                    
                }
                else{
                    num=num%500;
                    s+='D';
                    
                }
                
            }
                else if(num>=100){
                    if(num>=400){
                        num=num%400;
                        s+='C';
                        s+='D';
                        
                    }
                    else{
                        
                        for(z=0;z<num/100;z++){
                            s+='C';
                        }
                        num=num%100;
                        
                        
                    }
                    
                }
                      else if(num>=50){
                          if(num>=90){
                              num=num%90;
                              s+='X';
                              s+='C';
                              
                          }
                          else{
                               for(z=0;z<num/50;z++){
                                   s+='L';
                               }
                              num=num%50;
                              
                          }
                      }
                            else if(num>=10){
                                if(num>=40){
                                    num=num%40;
                                    s+='X';
                                    s+='L';
                                    
                                }
                                else{
                                    
                                    for(z=0;z<num/10;z++){
                                        s+='X';
                                        
                                    }
                                    num=num%10;

                                }
                            }
                                    else if(num>=5){
                                        if(num==9){
                                            s+='I';
                                            s+='X';
                                            num=0;
                                        }
                                        else{
                                            num=num%5;
                                            s+='V';
                                            
                                        }
                                    }
                                        else{
                                            if(num==4){
                                                s+='I';
                                                s+='V';
                                                num=0;
                                            }
                                            else{
                                                for(z=0;z<num;z++){
                                                    s+='I';
                                                      
                                                }
                                                num=0;
                                            }
                                        }
        }
        return s;
    }
};