document.addEventListener("keypress", function(event) {
    sound(event.key);
    });
function sound(key){
    switch (key){
        case "w":
            w_sound();
            break;
        case "a":
            a_sound();
            break;
        case "s":
            s_sound();
            break;           
        case "d":
            d_sound();
            break;            
        case "j":
            j_sound();
            break;
        case "k":
            k_sound();
            break;
        case "l":
            l_sound();
            break;           var snd = new Audio("sounds/tom-4.mp3");
            snd.play();
        }}


function w_sound(){
    var snd = new Audio("sounds/crash.mp3");
    snd.play();
}
document.getElementsByClassName("w drum")[0].addEventListener("click",w_sound)


function a_sound(){
    var snd = new Audio("sounds/kick-bass.mp3");
    snd.play();
}
document.getElementsByClassName("a drum")[0].addEventListener("click",a_sound)



function s_sound(){
    var snd = new Audio("sounds/snare.mp3");
    snd.play();
}
document.getElementsByClassName("s drum")[0].addEventListener("click",s_sound)



function d_sound(){
    var snd = new Audio("sounds/tom-1.mp3");
    snd.play();
}
document.getElementsByClassName("d drum")[0].addEventListener("click",d_sound)



function j_sound(){
    var snd = new Audio("sounds/tom-2.mp3");
    snd.play();
}
document.getElementsByClassName("j drum")[0].addEventListener("click",j_sound)



function k_sound(){
    var snd = new Audio("sounds/tom-3.mp3");
    snd.play();
}
document.getElementsByClassName("k drum")[0].addEventListener("click",k_sound)



function l_sound(){
    var snd = new Audio("sounds/tom-4.mp3");
    snd.play();
}
document.getElementsByClassName("l drum")[0].addEventListener("click",l_sound)



    
