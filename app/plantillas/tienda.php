<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <link rel="stylesheet" href="web/css/bootstrap.min.css">
    <link rel="stylesheet" type="text/css" href='web/css/style.css'>
    <script src="web/js/jquery-3.4.1.slim.min.js" defer></script>
    <script src="web/js/bootstrap.min.js" defer></script>
</head>
<style>
    .ima {
        width: 100%;
        height: 250;}
</style>

<body>
    <?php
    $navbar = true;
    ob_start();
    if (isset($compraExitosa)) { ?>
        <div class="alert alert-success" role="alert">
            Compra realizada con exito!
            <button type="button" class="close" data-dismiss="alert" aria-label="Close">
                <span aria-hidden="true">&times;</span>
            </button>
        </div>
    <?php } ?>

    <div class="carousel slide col-12" data-ride="carousel" style="height: 250px;">
        <div class="carousel-inner col-12">
            <?php foreach ($productos as $key => $value) {
                $direccion = "img/" . $value['Direccion'];
                if ($value['Indice'] == $productos[0]['Indice']) { ?>
                    <div class="carousel-item active col-12">
                    <?php } else { ?>
                        <div class="carousel-item col-12">
                        <?php } ?>
                        <img src="<?= $direccion ?>" class="ima">
                        </div>
                    <?php } ?>
                    </div>
        </div><br>
        <?php foreach ($productos as $key => $value) {
            $direccion = "img/" . $value['Direccion']; ?>
            <form method="post" class="col-6 justify-content-center" style="width: 18rem;">
                <div class="card">
                    <img src="<?= $direccion ?>" class="card-img-top" style="width:50px">
                    <div class="card-body col-12">
                        <h5 class="card-title row justify-content-center"><?= $value['Producto'] ?></h5>
                        <h6 class="card-text row justify-content-center"><?= $value['Texto'] ?></h6>
                        <input type="hidden" value="<?= $value['Indice'] ?>" name="indice">
                        <input type="hidden" value="<?= $rol ?>" name="rol">
                        <input type="submit" name="ver" value="Ver Artículo" class="btn btn-primary justify-content-center col-12">
                    </div>
                </div>

            </form>
            <br>
        <?php }
        $contenido = ob_get_clean();
        include 'base.php';
        ?>
</body>
<script type="text/javascript">
    (function($) {
        $('.carousel').carousel({
            interval: 2000
        });
    });
</script>

</html>