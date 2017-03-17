<!DOCTYPE html>
<html>
 <head>
	<meta charset="utf-8"/>
    <link rel="stylesheet" type="text/css" href="http://localhost:81/php/style.css">
</head>
<body id="targetBody">
    <header>
        <img src="https://encrypted-tbn2.gstatic.com/images?q=tbn:ANd9GcTDiPYn1kBOVpGZti_ugTpEMzjHcT_KzBH1ULTX7Hv79SiDtCJ6gmDFE_Y" />
        <h1><a href ="http://localhost:81/php/index.php">JavaScript</a></h1>        
    </header>
    <nav>
        <ol>
            <?php
                echo file_get_contents("list.txt");
             ?>
        </ol>
    </nav>
    <div id="control">
        <input type="button" value="white" onclick="document.getElementById('targetBody').className='white'"/>
        <input type="button" value="black" onclick="document.getElementById('targetBody').className='black'"/>
    </div>
    <article>
        <?php
        if(!empty($_GET['id'])){
            echo file_get_contents($_GET['id'].".txt");
        }
         ?>
    </article>
</body>
</html>
