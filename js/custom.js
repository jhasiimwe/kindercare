let btn = document.getElementById('sub');
btn.addEventListener('click',(event) => {
    let letter = document.getElementsClassName('letter');
    let number = 0;
    letter.forEach((letter) => {
        if (letter.checked) {
            number++;
        }
    });
    if(number>8){
        window.alert("select not more than 8 letters");
        event.preventDefault();
    }
});
