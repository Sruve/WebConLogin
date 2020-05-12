<!-- Vista común a la mayoría (sino todas) las vistas de la aplicación
     Suele contener la imagen corporativa de la apliación Web

     El nombre del archivo es indiferente: layout, comun, etc.
-->
<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <link rel="stylesheet" href="web/css/bootstrap.min.css">
  <link rel="stylesheet" type="text/css" href='web/css/style.css'>
</head>
<style>
  body {
    background-color: antiquewhite;
  }

  footer {
    background-color: black;
    color: white;
    text-align: center;
    height: 60%;
  }
</style>

<body>

  <?php if (isset($navbar)) { ?>
    <nav class="navbar navbar-expand-lg bg-light">
      <div class="collapse navbar-collapse">
        <ul class="navbar-nav">
          <li class="nav-item active">
            <a class="nav-link" href="">Home</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" >Resto de Links</a>
          </li>
        </ul>
        <?php if ($rol == 1) { ?>
          <form method="post" class="form-inline my-2 my-lg-0">
            <input type="hidden" value="<?= $rol ?>" name="rol">
            <input type="submit" name="anadir" value="Añadir producto" class="btn btn-primary col-12">
          </form>
        <?php } ?>
      </div>
    </nav><br>
   <!-- <div class="col-2">
      <form>
        <span> Genero</span><br>
        <ul id="genero">
          <li id="Accion"><a href=" #">Accion</a></li>
          <li id="Arcade"> <a href="#">Arcade</a></li>
          <li id="Deportivo"> <a href="#">Deportivo</a></li>
          <li id="Estrategia"> <a href="#">Estrategia</a></li>
        </ul><br>
        <span>Precio</span><br>
        <input type="range" id="precio" min="0" max="100"><br>
        <span>Pegi</span><br>
        <ul id="pegi">
          <li id="3"><a href="#">3</a></li>
          <li id="7"><a href="#">7</a></li>
          <li id="12"><a href="#">12</a></li>
          <li id="16"><a href="#">16</a></li>
          <li id="18"><a href="#">18</a></li>
        </ul><br>
        <span>Marcas</span><br>
        <ul id="marcas">
          <li id="Tencent"><a href="#">Tencent</a></li>
          <li id="Microsoft"><a href="#">Microsoft</a></li>
          <li id="Sony"><a href="#">Sony</a></li>
          <li id="Electronic Arts"><a href="#">Electronic Arts</a></li>
          <li id="Activision Blizzard"><a href="#">Activision Blizzard</a></li>
          <li id="Apple"><a href="#">Apple</a></li>
        </ul><br>
        <span>Segunda Mano</span><br>
        <ul id="segunda">
          <li id="Si"><a href="#">Si</a></li>
          <li id="No"><a href="#">No</a></li>
        </ul><br>
    </div>
    </form>
    </div>--><?php } ?>
  <div id="contenido">
    <?= $contenido ?>
  </div>
  <?php if (isset($navbar)) { ?>
    <footer class="footer col-12">
      Lorem, ipsum dolor sit amet consectetur adipisicing elit. Libero reiciendis molestiae quis architecto deleniti veniam, debitis sed aspernatur minima dolore tenetur molestias dolorem velit iusto perferendis. Fugit blanditiis tempora illum?
    </footer><?php } ?>
</body>

</html>