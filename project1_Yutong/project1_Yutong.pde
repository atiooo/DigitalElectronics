import processing.video.*;
import java.util.*;

int radius = 5;
int intensity_level = 20;
int num_pixels = 20;

Capture video;

void setup() {
  noCursor();
  size(500, 400);
  background(255);

  video = new Capture(this, width, height, "FaceTime HD Camera (Built-in)");
  video.start();

  frameRate(15);

  //size(1000, 500);
  //img  = loadImage("night.jpg");
  //image(img, 0, 0);
}

void captureEvent(Capture video) {
  // Read image from the camera
  video.read();
}

color readColor(color[] pixels, int x, int y) {
  return pixels[(width-1-x) + y*width];
  //return pixels[x + y*width];
}

void draw() {
  video.loadPixels();
  //img.loadPixels();
  for (int rand_y = 0; rand_y < height; rand_y++) {
    for (int rand_x = 0; rand_x < width; rand_x++) {
      int[] intensityCount = new int[intensity_level + 1];
      float[] averageR = new float[intensity_level + 1];
      float[] averageG = new float[intensity_level + 1];
      float[] averageB = new float[intensity_level + 1];

      int lo_x = (rand_x - radius) >=0 ? (rand_x - radius) : 0;
      int hi_x = (rand_x + radius) < width ? (rand_x + radius) : width - 1;
      int lo_y = (rand_y - radius) >=0 ? (rand_y - radius) : 0;
      int hi_y = (rand_y + radius) < height ? (rand_y + radius) : height - 1;

      //println(lo_x + " " + hi_x + " " + lo_y + " " + hi_y + " ");

      for (int x  = lo_x; x <= hi_x; x++) {
        for (int y = lo_y; y <= hi_y; y++) {
          //color c = get(x, y);
          color c = readColor(video.pixels, x, y);
          float r = red(c);
          float g = green(c);
          float b = blue(c);

          //println("r:" + r + " g:" + g + " b:" + b);
          //float test = 255;
          
          //int curIntensity = (int)(((double)((r+g+b)/3) * intensity_level)/test);
          int curIntensity = int((((r+g+b)/3.0)*intensity_level)/255.0);
          //println(curIntensity);
          intensityCount[curIntensity]++;
          averageR[curIntensity] += r;
          averageG[curIntensity] += g;
          averageB[curIntensity] += b;
        }
      }

      int maxIndex = 0;
      int max = 0;
      for (int i = 0; i <= intensity_level; i++) {
        if (intensityCount[i] > max) {
          max = intensityCount[i];
          maxIndex = i;
        }
      }

      int R = int(averageR[maxIndex] / max);
      int G = int(averageG[maxIndex] / max);
      int B = int(averageB[maxIndex] / max);

      color finalColor = color(R, G, B);

      set(rand_x, rand_y, finalColor);
    }
  }
}

void keyPressed() {
  if (key == CODED) {
    if (keyCode == UP) {
      radius++;
      //println(radius);
    }
    if (keyCode == DOWN) {
      radius--;
    }
  }
  if (key == ' ') {
    saveFrame("OilPaint##.png");
  }
}
