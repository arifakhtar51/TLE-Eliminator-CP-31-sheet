import cv2
import numpy as np

def detect_uniform_components(hsv, gender):
    
    if gender == 'boy':
        
        # Shirt (typically white )
        lower_shirt = np.array([100, 50, 50])
        upper_shirt = np.array([140, 255, 255])
        
        # Pants (typically black)
        lower_pants = np.array([100, 50, 50])
        upper_pants = np.array([140, 255, 255])
        
    elif gender == 'girl':
        
        # Shirt  (typically white )
        lower_shirt = np.array([0, 0, 200])
        upper_shirt = np.array([180, 30, 255])
        
        # Skirt  (varies, assume light or pastel colors for example)
        lower_skirt = np.array([0, 50, 100])
        upper_skirt = np.array([180, 255, 255])

    # Create masks for uniform components
    mask_shirt = cv2.inRange(hsv, lower_shirt, upper_shirt)
    mask_pants_or_skirt = cv2.inRange(hsv, lower_pants, upper_pants)

    return mask_shirt, mask_pants_or_skirt

def check_uniform(image_path, gender):
    # Load the image
    image = cv2.imread(image_path)
    
    # Convert to HSV color space
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    
    # Detect uniform components based on gender
    mask_shirt, mask_pants_or_skirt = detect_uniform_components(hsv, gender)
    
    # Check if masks have significant areas
    shirt_area = cv2.countNonZero(mask_shirt)
    pants_or_skirt_area = cv2.countNonZero(mask_pants_or_skirt)
    
    # Define thresholds for detection
    shirt_threshold = 5000
    pants_or_skirt_threshold = 5000
    
    if shirt_area > shirt_threshold and pants_or_skirt_area > pants_or_skirt_threshold:
        print(f"Uniform check passed for {gender}: Shirt and pants/skirt detected.")
    else:
        print(f"Uniform check failed for {gender}: Required uniform not detected.")
    
    # Display the image and masks
    cv2.imshow("Original Image", image)
    cv2.imshow("Shirt Mask", mask_shirt)
    cv2.imshow("Pants/Skirt Mask", mask_pants_or_skirt)
    
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# Test the function with an image path and gender
check_uniform('Arif.jpg', 'boy')  # or 'girl'
