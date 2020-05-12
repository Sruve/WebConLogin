<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <link rel="stylesheet" href="web/css/bootstrap.min.css">
    <link rel="stylesheet" type="text/css" href='web/css/style.css'>
</head>
<style>
</style>

<body>
    <?php 
    $navbar = true;
    ob_start();
    $rol = intval($rol);
    ?>
    <form method="post" class="col-6">
        <?php
        if (isset($errores)) { ?>
            <div class="alert alert-danger" role="alert">
                <?= reset($errores) ?>
                <button type="button" class="close" data-dismiss="alert" aria-label="Close">
                    <span aria-hidden="true">&times;</span>
                </button>
            </div>
        <?php }
        if (!isset($editar)) { ?>
            <div class="row">
                <div class="col-4 ">
                    <img src="<?= "img/" . $producto[0]['Direccion'] ?>" class="img-fluid">
                </div>
                <div class="col-8">
                    <h1><?= $producto[0]['Producto'] ?></h1>
                    <p><?= $producto[0]['TextoLargo'] ?></p>
                </div>
            </div>
            <div class="row">
                <div class="col-12">
                    <h6>Cantidad: <input type="number" min=0 max=<?= $producto[0]['Cantidad'] ?> name="cantidad" value="<?= $cantidad ?? '' ?>"></h6>
                    <h6>Precio:<?= $producto[0]['Precio'] ?>€</h6>
                </div>
            </div>
            <div class="row">
                <input type="hidden" value="<?= $producto[0]['Indice'] ?>" name="indice">
                <input type="hidden" value="<?= $rol ?>" name="rol">
                <input type="submit" name="comprar" value="Comprar" class="btn btn-primary col-4">&nbsp;
                <?php if ($rol == 1) : ?> &nbsp;
                    <input type="submit" name="editar" value="Editar" class="btn btn-primary col-3">
                <?php endif; ?>
                &nbsp; <input type="submit" name="atras" value="Atras" class="btn btn-primary col-3">
            </div>

           <?php } else if ($editar) { ?>
            <div class="form-group">
                <label>Indice</label>
                <input readonly type="text" value="<?= $producto[0]['Indice'] ?? ''  ?>" name="cambio[indice]" class="form-control">
            </div>
            <div class="form-group">
                <label>Nombre del Producto</label>
                <input type="text" value="<?= $producto[0]['Producto'] ?? ''  ?>" name="cambio[producto]" class="form-control">
            </div>
            <div class="form-group">
                <label>Texto descripcion corta</label>
                <textarea rows="2" cols="50" name="cambio[texto]" class="form-control"><?= $producto[0]['Texto'] ?? ''  ?></textarea>
            </div>
            <div class="form-group">
                <label>Texto descripcion larga</label>
                <textarea rows="4" cols="50" name="cambio[textolargo]" class="form-control"><?= $producto[0]['TextoLargo'] ?? ''  ?></textarea>
            </div>
            <div class="form-group">
                <div class="ima">
                </div>
                <input type="file" name="cambio[direccion]" value="<?= $producto[0]['Direccion'] ?? ''  ?>" accept=".jpg">
            </div>
            <div class="form-group">
                <label>Cantidad de unidades</label>
                <input type="number" value="<?= $producto[0]['Cantidad'] ?? ''  ?>" name="cambio[cantidad]" class="form-control">
            </div>
            <div class="form-group">
                <label>Precio</label>
                <input type="number" value="<?= $producto[0]['Precio'] ?? ''   ?>" name="cambio[precio]" class="form-control">
            </div>
            <div class="form-group">
                <input type="hidden" value="<?= $producto[0]['Indice'] ?>" name="indice">
                <input type="hidden" value="<?= $rol ?>" name="rol">
                <input type="submit" name="confirmarCambio" value="Confirmar" class="btn btn-primary">
                <input type="submit" name="eliminar" value="Eliminar" class="btn btn-primary">
                <input type="submit" name="atras" value="Atras" class="btn btn-primary">
            </div>
        <?php } else { ?>
            <div class="form-group">
                <label>Indice</label>
                <input readonly type="text" value="<?= $indice ?? ''  ?>" name="insertar[indice]" class="form-control">
            </div>
            <div class="form-group">
                <label>Nombre del Producto</label>
                <input type="text" name="insertar[producto]" class="form-control">
            </div>
            <div class="form-group">
                <label>Texto descripcion corta</label>
                <textarea rows="2" cols="50" name="insertar[texto]" class="form-control"></textarea>
            </div>
            <div class="form-group">
                <label>Texto descripcion larga</label>
                <textarea rows="4" cols="50" name="insertar[textolargo]" class="form-control"></textarea>
            </div>
            <div class="form-group">
                <div class="ima">
                </div>
                <input type="file" name="insertar[direccion]" accept=".jpg">
            </div>
            <div class="form-group">
                <label>Cantidad de unidades</label>
                <input type="number" name="insertar[cantidad]" class="form-control">
            </div>
            <div class="form-group">
                <label>Precio</label>
                <input type="number" name="insertar[precio]" class="form-control">
            </div>
            <div class="form-group">
                <input type="hidden" value="<?= $rol ?>" name="rol">
                <input type="submit" name="confirmarAnadir" value="Añadir" class="btn btn-primary">
                <input type="submit" name="atras" value="Atras" class="btn btn-primary">
            <?php } ?>
    </form><br> 
    <?php $contenido = ob_get_clean();
    include 'base.php';
    ?>
</body>

</html>