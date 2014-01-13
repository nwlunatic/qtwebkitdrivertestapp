function fillList(count){
    var list = document.getElementById('list');
    var ul = document.createElement("ul");
    for (var i = 0; i < count; i++) {
        var li = document.createElement("li");
        li.style.className = 'link';
        var a = document.createElement("a");
        a.innerHTML = "link" + i;
        a.onclick = document.getElementById("button").onclick = function(){
            updateResult(this.innerHTML);
        };
        li.appendChild(a);
        list.appendChild(li);
    }
}

fillList(20);

window.onload = function()
{
    document.getElementById("quit").onmousedown = function()
    {
        Qt.quit();
    };
}

function updateResult(text) {
    document.getElementById("result").innerHTML = text;
}

document.getElementById("button").onclick = function () {
    updateResult("button");
};

document.getElementById("input").onkeydown = function (event) {
    document.getElementById("input")
    if (event.keyCode == 13) {
        updateResult(event.target.value);
        event.target.value = "";
    }
}