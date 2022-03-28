<?php

$folder_stat    = 'download/stat/' ; // répertoire dans lequel seront stockées les statistiques
$folder_archive = 'download/' ; // répertoire des téléchargements

if ( isset( $_GET['file'] ) ) // si le visiteur veut télécharger un fichier
{
        $name = htmlentities($_GET['file'], ENT_QUOTES); // sécurisation de la variable
                
        if ( file_exists( $folder_stat . $name . '.txt' ) ) // si le fichier existe
        {       
                $FileContent = fopen( $folder_stat . $name . '.txt', 'r+' ); // ouverture du fichier statistique contenant le nombre de hits
        
                $hit = fgets( $FileContent ); // récupération de la valeur
                $hit = intval( $hit ); // on vérifie qu’il s’agisse bien d’un nombre
                $hit++; // ajout de 1 au nombre de hits
                
                fseek( $FileContent, 0 ); // réinitialisation du curseur
                fputs( $FileContent, $hit ); // écriture dans le fichier
                
                fclose( $FileContent ); // fermeture du fichier
                
                header( "Location: $folder_archive$name.zip" ); // redirection vers le téléchargement
        }
}

function NumberOfHit( $name ) // création de la fonction NumberOfHit
{
        $folder_stat = 'download/stat/' ; // répertoire dans lequel seront stockées les statistiques
        $file = $folder_stat . $name . '.txt' ; // nom du fichier de statistiques contenant le nombre de hits
        
        if ( file_exists( $file ) ) // si le fichier existe
        {
                $FileContent = fopen( $file , 'r' ); // ouverture du fichier
        
                $hit = fgets( $FileContent ); // récupération de la valeur
                fclose( $FileContent ); // fermeture du fichier
                
                return $hit; // retour de la valeur de $hit
        }
        else // si le fichier n’existe pas
        {
                touch( $file ); // création du fichier
                
                $FileContent = fopen( $file  , 'r+' ); // ouverture du fichier
        
                fseek( $FileContent, 0 ); // réinitialisation du curseur
                fputs( $FileContent, 0 ); // écriture dans le fichier
                
                fclose( $FileContent ); // fermeture du fichier
        }
}

?>

<html>

<head>
<title>Download English</title>
<style type="text/css">
* {
        font-family: Verdana, Arial, serif;
        font-size: 20px;
}
       
</style>
<link rel="stylesheet" href="w3.css" />
<link rel="stylesheet" href="style.css" />
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>

<body>
<?php
        
$name   = 'test' ; // nom du fichier (et de l’archive)
$result = NumberOfHit( $name ) ; // récupération du nombre de hits pour le nom concerné
        
echo '
<p>
        Download the folder : <a href="?file=' . $name . '">Direct download</a>
</p>
';

?>
</body>


<element13>
        <a href="http://localhost/Norway/Administration English.php" class="w3-button w3-block w3-gray w3-left-align" style="width:55%"><i class="fa fa-reply" style="font-size:20px;color:black"></i> Return</a>
</element13>


</html>
