document.getElementById("convertBtn").addEventListener("click", function() {
    const tempInput = parseFloat(document.getElementById("tempInput").value);
    const tempScale = document.getElementById("tempScale").value;
    let tempInCelsius, tempInFahrenheit, tempInKelvin;

    if (tempScale === "celsius") {
        tempInCelsius = tempInput;
        tempInFahrenheit = (tempInCelsius * (9 / 5)) + 32;
        tempInKelvin = tempInCelsius + 273.15;
    } else if (tempScale === "fahrenheit") {
        tempInFahrenheit = tempInput;
        tempInCelsius = (tempInFahrenheit - 32) * (5 / 9);
        tempInKelvin = tempInCelsius + 273.15;
    } else if (tempScale === "kelvin") {
        tempInKelvin = tempInput;
        tempInCelsius = tempInKelvin - 273.15;
        tempInFahrenheit = (tempInCelsius * (9 / 5)) + 32;
    }

    // Display results
    const resultDiv = document.getElementById("result");
    resultDiv.innerHTML = `
        Temperature in Celsius: ${tempInCelsius.toFixed(2)} °C <br>
        Temperature in Fahrenheit: ${tempInFahrenheit.toFixed(2)} °F <br>
        Temperature in Kelvin: ${tempInKelvin.toFixed(2)} K
    `;
});
