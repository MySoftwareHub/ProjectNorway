<?php
session_start();
if (isset($_SESSION['connect']))//On vérifie que le variable existe.
{
        $connect=$_SESSION['connect'];//On récupère la valeur de la variable de session.
}
else
{
        $connect=0;//Si $_SESSION['connect'] n'existe pas, on donne la valeur "0".
}
       
if ($connect == "1") // Si le visiteur s'est identifié.
{
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
        <title>Projekt Norge/Historisk Stasjon 8</title>
    </head>
 
    <script type="text/javascript">
    //AJAX Method
    function reFresh() {
    location.reload(true)
    }
    
    window.setInterval("reFresh()",60000);
    </script>



    <body>
 
   

    <header>
        <div class="w3-container w3-indigo">
            <h2>Aurora Project</h2>
        </div>
    </header>
    

   
   <div id="conteneur">
        <nav>
             <div class="w3-dropdown-hover">
                    <button class="w3-button w3-indigo w3-left-align" style="width:187%"><i class="fa fa-dashboard" style="font-size:20px;color:white"></i> Dashbord
                    </button>
                <div class="w3-dropdown-content w3-bar-block w3-blue w3-left-align" style="width:187%">
                    <a href="http://localhost/Norway/Dashbord Stasjon 1 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 1</a>
                    <a href="http://localhost/Norway/Dashbord Stasjon 2 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 2</a>
                    <a href="http://localhost/Norway/Dashbord Stasjon 3 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 3</a>
                    <a href="http://localhost/Norway/Dashbord Stasjon 4 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 4</a>
                    <a href="http://localhost/Norway/Dashbord Stasjon 5 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 5</a>
                    <a href="http://localhost/Norway/Dashbord Stasjon 6 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 6</a>
                    <a href="http://localhost/Norway/Dashbord Stasjon 7 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 7</a>
                    <a href="http://localhost/Norway/Dashbord Stasjon 8 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 8</a>
                </div>
            </div> 

            <div class="w3-dropdown-hover">
                    <button class="w3-button w3-indigo w3-left-align" style="width:193%"><i class="fa fa-bar-chart" style="font-size:20px;color:white"></i> Historisk
                    </button>
                <div class="w3-dropdown-content w3-bar-block w3-blue w3-left-align" style="width:193%">
                    <a href="http://localhost/Norway/Historisk Stasjon 1 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 1</a>
                    <a href="http://localhost/Norway/Historisk Stasjon 2 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 2</a>
                    <a href="http://localhost/Norway/Historisk Stasjon 3 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 3</a>
                    <a href="http://localhost/Norway/Historisk Stasjon 4 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 4</a>
                    <a href="http://localhost/Norway/Historisk Stasjon 5 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 5</a>
                    <a href="http://localhost/Norway/Historisk Stasjon 6 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 6</a>
                    <a href="http://localhost/Norway/Historisk Stasjon 7 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 7</a>
                    <a href="http://localhost/Norway/Historisk Stasjon 8 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 8</a>
                </div>
            </div> 




            <div class="w3-dropdown-hover">
                    <button class="w3-button w3-indigo w3-left-align" style="width:187.5%"><i class="fa fa-exclamation-triangle" style="font-size:20px;color:white">
                    </i> Sikkerhet                                                             
                    </button>
                <div class="w3-dropdown-content w3-bar-block w3-blue w3-left-align" style="width:187.5%">
                    <a href="http://localhost/Norway/Sikkerhet Stasjon 1 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 1</a>
                    <a href="http://localhost/Norway/Sikkerhet Stasjon 2 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 2</a>
                    <a href="http://localhost/Norway/Sikkerhet Stasjon 3 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 3</a>
                    <a href="http://localhost/Norway/Sikkerhet Stasjon 4 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 4</a>
                    <a href="http://localhost/Norway/Sikkerhet Stasjon 5 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 5</a>
                    <a href="http://localhost/Norway/Sikkerhet Stasjon 6 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 6</a>
                    <a href="http://localhost/Norway/Sikkerhet Stasjon 7 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 7</a>
                    <a href="http://localhost/Norway/Sikkerhet Stasjon 8 Norsk.php" class="w3-bar-item w3-button"><i class="fa fa-rss-square " style="font-size:20px;color:white"></i> Stasjon 8</a>
                </div>
            </div> 



            <a href="http://localhost/Norway/Administrasjon Norsk.php" class="w3-button w3-block w3-indigo w3-left-align" style="width:100.5%"> <i class="fa fa-wrench" style="font-size:20px;color:white"></i> Administrasjon</a>

            <div class="w3-display-container " style="height:550px;width:242px">
                <div class="w3-dark-gray w3-display-topleft" style="width:100%;height:100%"></div>
            </div> 
        </nav>


        <section>
            <h1><i class="fa fa-bar-chart" style="font-size:50px;color:white"></i> Historisk Stasjon 8</h1>
        </section>
    </div>

    <element3>
                 <a href="http://localhost/Norway/index.php" class="w3-button w3-block w3-gray w3-left-align" style="width:50%"><i class="fa fa-user" style="font-size:20px;color:black"></i> Logg Ut</a>
    </element3>


 <element4>
                 <div class="w3-dropdown-hover">
                    <button class="w3-button w3-gray w3-left-align" style="width:100%"> Språk                                                              
                    </button>
                <div class="w3-dropdown-content w3-bar-block w3-gray w3-left-align" style="width:100%">
                    <a href="http://localhost/Norway/Historic Station 8 English.php" class="w3-bar-item w3-button"> Engelsk</a>
                    <a href="http://localhost/Norway/Historisk Stasjon 8 Norsk.php" class="w3-bar-item w3-button"> Norsk</a>
                </div>
            </div> 
        </element4>


   <?php
}
 
else // Le mot de passe n'est pas bon.
{
// On affiche la zone de texte pour rentrer le mot de passe.
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr">
    <head>
<title>Visiteur inconnu</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<link rel="stylesheet" media="screen" type="text/css" title="suite" href="design_accueil.css" />
        <!-- Lien vers la favicon -->      
<link rel="shortcut icon" type="image/x-icon" href="images/favicon.ico" height="48" width="48"/>
    </head>
 
    <body>
   
    <!-- Le corps -->
   
     <div id="corps">
<p>Veuillez vous identifier pour accéder au site :</p>
 
<form action="index.php" method="post">
<p>
<input type="submit" value="OK" />
</p>
</form>
        </div>
       
        <!-- Le pied de page -->
 
           <div id="pied_de_page1">
           
       </div>
       
    </body>
</html>


   <?php
 
} // Fin du else.
 
// Fin du code. :)
?>

        
        
        

 

    


   
    



    </body>
</html>