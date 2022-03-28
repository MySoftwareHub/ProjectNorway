<?php
session_start();// À placer obligatoirement avant tout code HTML.
 
$_SESSION['connect']=0; //Initialise la variable 'connect'.
 
if (isset($_POST['mot_de_passe']) AND isset($_POST['login'])) // Si les variables existent.
{
        $mot_de_passe=$_POST['mot_de_passe'];
        $login=$_POST['login'];//On récupère les données envoyées par la méthode POST du formulaire d'identification.
}
 
else // Les variables n'existent pas encore.
{
        $mot_de_passe="";
        $login="";// On crée des variables $mot_de_passe  et $login vides.
}
 
if (($mot_de_passe == "elektro" AND $login == "elektro"))
// Si le mot de passe et le login sont bons (valable pour 1 utilisateur ou plus). J'ai mis plusieurs identifiants et mots de passe.
 
{
        $_SESSION['connect']=1; // Change la valeur de la variable connect. C'est elle qui nous permettra de savoir s'il y a eu identification.
        $_SESSION['login']=$login;// Permet de récupérer le login afin de personnaliser la navigation.
// On affiche la page cachée.
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <link rel="stylesheet" href="w3.css" />
        <link rel="stylesheet" href="style.css" />
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
        <title>Project Norway/Dashboard Station 1</title>
    </head>
 
   
    
 	
   


    <body>
 
        
    

   
    <header>
        <div class="w3-container w3-indigo">
            <h2>Aurora Project</h2>
        </div>
    </header>
    

   
   <div id="conteneur">
        <nav>


             <div class="w3-dropdown-hover">
                    <button class="w3-button w3-indigo w3-left-align" style="width:172.5%"><i class="fa fa-dashboard" style="font-size:20px;color:white"></i> Dashboard
                    </button>
                <div class="w3-dropdown-content w3-bar-block w3-blue w3-left-align" style="width:172.5%">
                    <a href="http://localhost/Norway/Dashboard Station 1 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 1</a>
                    <a href="http://localhost/Norway/Dashboard Station 2 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 2</a>
                    <a href="http://localhost/Norway/Dashboard Station 3 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 3</a>
                    <a href="http://localhost/Norway/Dashboard Station 4 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 4</a>
                    <a href="http://localhost/Norway/Dashboard Station 5 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 5</a>
                    <a href="http://localhost/Norway/Dashboard Station 6 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 6</a>
                    <a href="http://localhost/Norway/Dashboard Station 7 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 7</a>
                    <a href="http://localhost/Norway/Dashboard Station 8 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 8</a>
                </div>
            </div> 


             <div class="w3-dropdown-hover">
                    <button class="w3-button w3-indigo w3-left-align" style="width:203%"><i class="fa fa-exclamation-triangle" style="font-size:20px;color:white"></i> Security                           
                                                             
                    </button>
                <div class="w3-dropdown-content w3-bar-block w3-blue w3-left-align" style="width:203%">
                    <a href="http://localhost/Norway/Security Station 1 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 1</a>
                    <a href="http://localhost/Norway/Security Station 2 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 2</a>
                    <a href="http://localhost/Norway/Security Station 3 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 3</a>
                    <a href="http://localhost/Norway/Security Station 4 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 4</a>
                    <a href="http://localhost/Norway/Security Station 5 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 5</a>
                    <a href="http://localhost/Norway/Security Station 6 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 6</a>
                    <a href="http://localhost/Norway/Security Station 7 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 7</a>
                    <a href="http://localhost/Norway/Security Station 8 English.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Station 8</a>
                </div>
            </div> 

              <a href="http://localhost/Norway/Administration English.php" class="w3-button w3-block w3-indigo w3-left-align" style="width:100.5%"> <i class="fa fa-wrench" style="font-size:20px;color:white"></i>  Administration</a>




            <div class="w3-display-container " style="height:720px;width:242px">
                <div class="w3-dark-gray w3-display-topleft" style="width:100%;height:100%"></div>
            </div> 
            
       

    </nav>



        


        <section>
            <h1><i class="fa fa-dashboard" style="font-size:50px;color:white"></i> Dashboard Station 1</h1>
        </section>


 <element1>







                            <?php  
                    $db = new SQLite3('Database.db');
                    $result = $db->query('SELECT Luminosity FROM Data_Arduino WHERE Station = 1 ORDER BY id DESC LIMIT 1 ');
                    while ($row = $result->fetchArray())
                    {
                    ?>


                      <?php 
                    if ( $row[0] < 40 )
                    {
                    ?>
                
                <div class="w3-panel w3-round-large w3-xxxlarge w3-amber">
                    <p><i class="material-icons" style="font-size:50px;color:white;" >brightness_high</i>  Very bright </p>
                        
                </div>

                <?php 
                    }
                 ?>



                    <?php 
                    if ( $row[0] >= 40  && $row[0] < 100 )
                    {
                    ?>
                
                <div class="w3-panel w3-round-large w3-xxxlarge w3-orange">
                   <p><i class="material-icons" style="font-size:50px;color:white;" >brightness_medium</i>  Medium </p>
                </div>

                <?php 
                    }
                 ?>




                  <?php 
                    if ( $row[0] >= 100 && $row[0] < 200 )
                    {
                    ?>
                
                <div class="w3-panel w3-round-large w3-xxxlarge w3-dark-gray">
                   <p><i class="material-icons" style="font-size:50px;color:white;" >brightness_low</i>  Dark </p>
                </div>

                <?php 
                    }
                 ?>
                 


                  <?php 
                    if ( $row[0] >= 200  )
                    {
                    ?>
                
                <div class="w3-panel w3-round-large w3-xxxlarge w3-black">
                 
                   <p><i class="material-icons" style="font-size:50px;color:white;" >brightness_3</i>  Night </p>
                
                </div>

                <?php 
                    }
                 ?>

                         

                    <?php 
                    }
                    $db->close(); 
                    ?>

            
               
        </element1>
       



















        
         <element2>
                    <?php  
                    $db = new SQLite3('Database.db');
                    $result = $db->query('SELECT Temperature FROM Data_Arduino WHERE Station = 1 ORDER BY id DESC LIMIT 1 ');
                    while ($row = $result->fetchArray())
                    {
                    ?>


                      <?php 
                    if ( $row[0] < 0 )
                    {
                    ?>
                
                <div class="w3-panel w3-round-large w3-xxxlarge w3-blue">
                    <p><i class="fa fa-thermometer-empty" style="font-size:50px;color:white"></i>   
                        <?php
                            print($row[0]);
                        ?>°C</p>
                </div>

                <?php 
                    }
                 ?>









                    <?php 
                    if ( $row[0] >= 0 && $row[0] < 10 )
                    {
                    ?>
                
                <div class="w3-panel w3-round-large w3-xxxlarge w3-green">
                    <p><i class="fa fa-thermometer-half" style="font-size:50px;color:white"></i>   
                        <?php
                            print($row[0]);
                        ?>°C</p>
                </div>

                <?php 
                    }
                 ?>




                  <?php 
                    if ( $row[0] >= 10 && $row[0] < 20 )
                    {
                    ?>
                
                <div class="w3-panel w3-round-large w3-xxxlarge w3-amber">
                    <p><i class="fa fa-thermometer-three-quarters" style="font-size:50px;color:white"></i>   
                        <?php
                            print($row[0]);
                        ?>°C</p>
                </div>

                <?php 
                    }
                 ?>
                 


                  <?php 
                    if ( $row[0] >= 20  )
                    {
                    ?>
                
                <div class="w3-panel w3-round-large w3-xxxlarge w3-red">
                    <p><i class="fa fa-thermometer-full" style="font-size:50px;color:white"></i>   
                        <?php
                            print($row[0]);
                        ?>°C</p>
                </div>

                <?php 
                    }
                 ?>

                         













                    <?php 
                    }
                    $db->close(); 
                    ?>

                


        </element2>
       


       
        <element3>
                 <a href="http://localhost/Norway/index.php" class="w3-button w3-block w3-gray w3-left-align" style="width:50%"><i class="fa fa-user" style="font-size:20px;color:black"></i> Log Out</a>
        </element3>

         <element4>
                 <div class="w3-dropdown-hover">
                    <button class="w3-button w3-gray w3-left-align" style="width:100%"> Language                                                              
                    </button>
                <div class="w3-dropdown-content w3-bar-block w3-gray w3-left-align" style="width:100%">
                    <a href="http://localhost/Norway/Dashboard Station 1 English.php" class="w3-bar-item w3-button"> English</a>
                    <a href="http://localhost/Norway/Dashbord Stasjon 1 Norsk.php" class="w3-bar-item w3-button"> Norwegian</a>
                </div>
            </div> 
        </element4>


    </body>
</html>



<?php
}
 
else // Le mot de passe n'est pas bon.
{
// On affiche la zone de texte pour rentrer le mot de passe.
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr">
    <head>
        <title>Identification</title>
        <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
        <link rel="stylesheet" href="w3.css" />
        <link rel="stylesheet" href="style.css" />
    </head>
    <body>
   
   
   
 <div class="w3-container w3-indigo">
  <h2>Aurora Project</h2>
</div>

 


<form action="index.php" method="post">

<element5><p> Login : </p>
<input type="text" name="login"/>
</element5>   

<element6><p>
Password : </p>
<input type="password" name="mot_de_passe"/>
</element6>


<element7><p>
<input type="submit" value="Submit"/>
</p></element7>
    

</form>
    

   
   
      
       
    </body>
</html>

<?php
 
} // Fin du else.
 
// Fin du code. :)
?>
