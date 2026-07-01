

import { saveData } from "./storage.js";

class CustomerFormHandler {

    constructor() {
        this.form = document.getElementById("hotelForm");
        this.bindEvents();
    }

    bindEvents() {

        this.form.addEventListener("submit", (e) => {
            e.preventDefault();

            if (this.validateForm()) {
                this.saveData();
                this.form.reset();
                this.showMessage("Data Saved Successfully!", "success");
            } else {
                this.showMessage("Please fix validation errors!", "error");
            }
        });

        // Real-time validation
        document.querySelectorAll("input, textarea").forEach(input => {
            input.addEventListener("blur", () => this.validateField(input));
        });
    }

    // FIELD VALIDATION (REAL TIME)
    validateField(input) {

        const value = input.value.trim();

        switch (input.id) {

            case "name":
                if (value.length < 3)
                    this.showError("nameError", "Name must be at least 3 characters");
                else this.showError("nameError", "");
                break;

            case "phone":
                if (!/^[0-9]{10}$/.test(value))
                    this.showError("phoneError", "Phone must be 10 digits");
                else this.showError("phoneError", "");
                break;

            case "email":
                if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(value))
                    this.showError("emailError", "Invalid email");
                else this.showError("emailError", "");
                break;

            case "aadhar":
                if (!/^[0-9]{12}$/.test(value))
                    this.showError("aadharError", "Aadhar must be 12 digits");
                else this.showError("aadharError", "");
                break;

            case "checkin":
            case "checkout":
                this.validateDates();
                break;
        }
    }

    // FORM VALIDATION (FINAL CHECK)
    validateForm() {

        let valid = true;

        const name = document.getElementById("name").value;
        const phone = document.getElementById("phone").value;
        const email = document.getElementById("email").value;
        const aadhar = document.getElementById("aadhar").value;

        const checkin = document.getElementById("checkin").value;
        const checkout = document.getElementById("checkout").value;

        //  FIXED DATE VALIDATION
        const today = new Date();
        today.setHours(0, 0, 0, 0);

        const checkinDate = new Date(checkin);
        const checkoutDate = new Date(checkout);

        if (checkinDate < today) {
            valid = false;
            this.showError("checkinError", "Check-in date cannot be past date");
        } else {
            this.showError("checkinError", "");
        }

        if (checkoutDate < checkinDate) {
            valid = false;
            this.showError("checkoutError", "Check-out must be after check-in");
        } else {
            this.showError("checkoutError", "");
        }

        // OTHER VALIDATIONS
        if (name.length < 3) valid = false;
        if (!/^[0-9]{10}$/.test(phone)) valid = false;
        if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email)) valid = false;
        if (!/^[0-9]{12}$/.test(aadhar)) valid = false;

        return valid;
    }

    // REAL TIME DATE VALIDATION
    validateDates() {

        const checkin = document.getElementById("checkin").value;
        const checkout = document.getElementById("checkout").value;

        const today = new Date();
        today.setHours(0, 0, 0, 0);

        const checkinDate = new Date(checkin);
        const checkoutDate = new Date(checkout);

        if (checkin && checkinDate < today) {
            this.showError("checkinError", "Check-in date cannot be past date");
        } else {
            this.showError("checkinError", "");
        }

        if (checkout && checkin && checkoutDate < checkinDate) {
            this.showError("checkoutError", "Check-out must be after check-in");
        } else {
            this.showError("checkoutError", "");
        }
    }

    // ERROR DISPLAY
    showError(id, message) {
        const el = document.getElementById(id);
        if (el) el.innerText = message;
    }

    // MESSAGE BOX (SUCCESS / ERROR)
    showMessage(msg, type) {

        let box = document.getElementById("message");

        box.innerHTML = `
            <div class="alert ${type === "success" ? "alert-success" : "alert-danger"}">
                ${msg}
            </div>
        `;

        setTimeout(() => {
            box.innerHTML = "";
        }, 3000);
    }

    // SAVE DATA
    saveData() {

        let data = {
            name: document.getElementById("name").value,
            phone: document.getElementById("phone").value,
            email: document.getElementById("email").value,
            address: document.getElementById("address").value,
            aadhar: document.getElementById("aadhar").value,
            checkin: document.getElementById("checkin").value,
            checkout: document.getElementById("checkout").value,
            adult: document.getElementById("adult").value,
            purpose: document.getElementById("purpose").value
        };

        saveData(data);
    }
}

new CustomerFormHandler();