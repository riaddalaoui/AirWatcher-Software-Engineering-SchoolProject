<h1>AirWatcher - Air Quality Monitoring and Analysis Tool</h1>

<h2>Overview</h2>
AirWatcher is a software application developed for a fake governmental agency tasked with environmental protection (it's a school project). The application focuses on analyzing, monitoring, and reporting air quality across a wide geographic area using data collected from various sensors. It provides a suite of tools for calculating air quality indices, analyzing sensor data, and measuring the effectiveness of air purifiers. 

<h2>Features</h2>

- <b>Air Quality Index (AQI) Calculation</b>: 
  - **computeAQIMoment**: Calculates the average AQI within a specified circle for a single day.
  - **computeAQIPeriode**: Computes the average AQI over a specified time period within a given radius.
- <b>Sensor Analysis</b>: 
  - **analyzeSensor**: Validates sensor accuracy by comparing its readings to those from the five nearest sensors.
  - **compareSensor**: Ranks sensors by their similarity to a specified sensor over a given time period.
- <b>Air Quality Improvement Measurement</b>: 
  - **measureImprovement**: Measures the improvement in air quality before and after the operation of an air purifier.
  - **measureAreaEffect**: Determines the radius of the area where air quality has improved due to an air purifier.
- <b>Sensor and Measurement Management</b>: 
  - **markMalicious**: Flags a user as malicious if their sensor is found to be providing unreliable data.
  - **addPoint**: Adds points to users when their sensor data is used.
  - **allSensors**: Retrieves a list of all sensors in the system.
  - **sensorsInCircle**: Finds all sensors within a specified radius of a given location.
  - **rankedSensors**: Provides a ranked list of sensors based on their proximity to a specific point.

<h2>Project Structure</h2>

- <b>Data Access Layer</b>: Manages data retrieval from CSV files, including sensor data, measurements, and user information.
- <b>Service Layer</b>: Implements the core business logic, including all the AQI calculations, sensor analysis, and air quality improvement measurements.
- <b>Interface Layer</b>: Provides a console-based interface for user interaction, allowing users to request data and receive reports.

<h2>Technologies Used</h2>

- <b>C++</b>: The primary programming language used for developing AirWatcher.
- <b>Git</b>: Version control system for managing project changes and collaboration.
- <b>CSV Files</b>: Used for storing and retrieving data related to sensors, measurements, users, and air purifiers.

<h2>Environments Used</h2>

- <b>Windows / Linux / MacOS </b>: The project has been tested and developed across these operating systems.
