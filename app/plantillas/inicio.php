<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">


    <link rel="stylesheet" href="web/css/bootstrap.min.css">
    <link rel="stylesheet" type="text/css" href='web/css/style.css'>
</head>

<body>
    <?php ob_start() ?>
    <?php if (isset($exito)) { ?>
        <div class="alert alert-primary" role="alert">
            Registro exitoso!
            <button type="button" class="close" data-dismiss="alert" aria-label="Close">
                <span aria-hidden="true">&times;</span>
            </button>
        </div>
    <?php }else if(isset($errores)){
        $error = null;
        if(isset($errores['usuario'])){
            $error=$errores['usuario'];
        }else if(isset($errores['contra'])){
            $error = $errores['contra'];
        }else if(isset($errores['errorLogin'])){
            $error = $errores['errorLogin'];
        }else{
            $error = "Error desconocido. Contacte con un administrador";
        } ?>
        <div class="alert alert-danger" role="alert">
            <?=$error?>
            <button type="button" class="close" data-dismiss="alert" aria-label="Close">
                <span aria-hidden="true">&times;</span>
            </button>
        </div>
   <?php } ?>
    <form method="post">
        <div class="row align-items-center ">
            <label>Usuario:
                <input type="text" name="loggin[usuario]" value="<?= $loggin['usuario'] ?? '' ?>" required>
            </label><br>
        </div>
        <div class="row align-items-center">
            <label>Contraseña:
                <input type="password" name="loggin[contra]" value="<?= $loggin['contra'] ?? '' ?>" required>
            </label><br>
        </div>
        <div class="row align-items-center">
            <div>
                <input type="submit" name="login" value="Login" class="btn btn-primary">
                <input type="submit" name="registrar" value="Registrar" class="btn btn-primary">
            </div>
        </div>
        <div class="row align-items-center">
        </div>
    </form>

    <?php $contenido = ob_get_clean() ?>
    <?php include 'base.php' ?>
</body>

</html>