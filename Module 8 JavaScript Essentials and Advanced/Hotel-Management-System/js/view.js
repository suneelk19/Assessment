

import { getData, deleteData } from "./storage.js";

function loadData(search = "") {
    const table = document.getElementById("tableData");

    let data = getData();
    let html = "";

    data.forEach((item, index) => {

        let nameMatch = item.name.toLowerCase().includes(search);
        let dateMatch = item.checkin.includes(search);

        if (nameMatch || dateMatch) {
            html += `
            <tr>
                <td>${item.name}</td>
                <td>${item.phone}</td>
                <td>${item.email}</td>
                <td>${item.address}</td>
                <td>${item.aadhar}</td>
                <td>${item.checkin}</td>
                <td>${item.checkout}</td>
                <td>${item.adult}</td>
                <td>${item.purpose}</td>
                <td>
                    <button class="btn btn-danger btn-sm" onclick="removeItem(${index})">
                        Delete
                    </button>
                </td>
            </tr>
            `;
        }
    });

    if (html === "") {
        html = `<tr><td colspan="10" class="text-center text-danger">No Data Found</td></tr>`;
    }

    table.innerHTML = html;
}

// DELETE
window.removeItem = function(index) {
    deleteData(index);
    loadData();
};

// INIT (IMPORTANT FIX)
window.onload = function () {

    loadData();

    const searchBox = document.getElementById("searchBox");

    if (searchBox) {
        searchBox.addEventListener("input", function () {
            loadData(this.value.toLowerCase());
        });
    }
};