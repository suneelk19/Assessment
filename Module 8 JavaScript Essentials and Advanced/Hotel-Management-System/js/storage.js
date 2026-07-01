


const KEY = "hotelData";

export function saveData(data) {
    let arr = JSON.parse(localStorage.getItem(KEY)) || [];
    arr.push(data);
    localStorage.setItem(KEY, JSON.stringify(arr));
}

export function getData() {
    return JSON.parse(localStorage.getItem(KEY)) || [];
}

export function deleteData(index) {
    let arr = JSON.parse(localStorage.getItem(KEY)) || [];
    arr.splice(index, 1);
    localStorage.setItem(KEY, JSON.stringify(arr));
}