//=========================================
//HTML + CSS + JavaScript codes for webpage
//=========================================
const char webpageCode[] =
R"=====(
<!DOCTYPE html>
<html>
<head>
    <title>Page Title</title>
    <style>
        h1{
            text-align: center;
        }
        p{
            text-align:center;
            font-size: 20px;
        }
        .color-picker{
            height: 40px;
            width:  25%;
        }
        .input-label{
            font-size: 26px;
        }
        .single-input{
            margin-bottom: 40px;
        }
        .submit{
            height: 40px;
            width:  25%;
            font-size: 30px;
        }
        .box-select{
            height: 40px;
            width:  25%;
        }
        .f1{
            position: relative;
            left: 37%;
        }
        .range{
            width:  25%;
        }
    </style>
</head>
<body>
    <h1>Select what your LED strip should show!</h1>

    <div class="f1">
        <form method="post" enctype="application/x-www-form-urlencoded" action="/">
            <div class="single-input">
                <input type="radio"  name="submit-type" value="static-color" data-id="static-color">
                <label>Static color</label><br>
                <input type="radio" name="submit-type" value="static-prefab" data-id="static-prefab">
                <label>Static prefab</label><br>
                <input type="radio" name="submit-type" value="animation">
                <label>Animation</label><br>
                <input type="radio" name="submit-type" value="brightness">
                <label>Brightness</label><br>
            </div>

            <div class="single-input" id="static-color">
                <label class="input-label">Static color:</label><br>
                <input type="color" name="color" class="color-picker"><br>
            </div>

            <div class="single-input" id="static-prefab">
                <label class="input-label">Static prefab:</label><br>
                <select name="static-prefab" class="box-select">
                    <option value="rainbow">Rainbow</option>
                    <option value="bi-color">Bi-Color</option>
                </select>                
            </div>

            <div class="single-input">
                <label class="input-label">Animation:</label><br>
                <select name="animation" class="box-select">
                    <option value="color-fade">Color Fade</option>
                    <option value="rainbow">Rainbow</option>
                </select>
            </div>

            <div class="single-input">
                <label class="input-label">Brightness:</label><br>
                <input type="range" name="brightness" class="range" min="0" max="100"><br>
            </div>

            <input type="submit" value="Submit" class="submit">
        </form>
    </div>

<script>
    $(':radio').change(function (event) {
    var id = $(this).data('id');
    $('#' + id).addClass('single-input').siblings().removeClass('single-input');
    });
</script>
</body>
</html>
)=====";
